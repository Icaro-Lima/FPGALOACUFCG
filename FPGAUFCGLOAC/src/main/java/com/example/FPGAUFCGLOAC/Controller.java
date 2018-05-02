package com.example.FPGAUFCGLOAC;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {

	private HashMap<String, Long> times = new HashMap<>();
	
	@RequestMapping(value = "/compile")
	public synchronized ResponseEntity<String> someMethod(@RequestParam("code") String code, HttpServletRequest request)
			throws InterruptedException, IOException {

		if (times.containsKey(request.getRemoteAddr())) {
			if (System.currentTimeMillis() - times.get(request.getRemoteAddr()) <= 5000) {
				return new ResponseEntity<String>("O golpe apressado normalmente se perde.", HttpStatus.TOO_MANY_REQUESTS);
			}
		}
		
		times.put(request.getRemoteAddr(), System.currentTimeMillis());

		/* Lendo e substituindo no Template.
		File file = new File("..\\FPGA_LOAC_UFCG_Backend\\Template.sv");
		FileInputStream fis = new FileInputStream(file);
		byte[] data = new byte[(int) file.length()];
		fis.read(data);
		fis.close();

		String templateReplaced = new String(data, "UTF-8");

		templateReplaced = templateReplaced.replace("CODEHERE", code);
		// End.*/

		// Escrevendo no Main.sv.
		PrintWriter writer = new PrintWriter("..\\FPGA_LOAC_UFCG_Backend\\Main.sv", "UTF-8");
		writer.print(code);
		writer.close();
		// End.

		ProcessBuilder builder = new ProcessBuilder("cmd.exe", "/c",
				"cd \"..\\FPGA_LOAC_UFCG_Backend\" && \"..\\verilator-3.841\\verilator.exe\" -cc Main.sv");

		Process p = builder.start();
		BufferedReader err = new BufferedReader(new InputStreamReader(p.getErrorStream()));

		String line;
		if ((line = err.readLine()) != null && line.startsWith("%Error")) {
			String fullError = line;
			while ((line = err.readLine()) != null) {
				fullError += line;
			}

			return new ResponseEntity<String>(fullError, HttpStatus.BAD_REQUEST);
		}

		builder = new ProcessBuilder("cmd.exe", "/c",
				"cd \"..\\FPGA_LOAC_UFCG_Backend\" && g++ -I\"..\\verilator-3.841\\include\" -I\"obj_dir\" \"..\\verilator-3.841\\include\\verilated.cpp\" obj_dir/VMain__Syms.cpp  obj_dir/VMain.cpp Main.cpp");

		p = builder.start();
		err = new BufferedReader(new InputStreamReader(p.getErrorStream()));

		if ((line = err.readLine()) != null) {
			String fullError = line;
			while ((line = err.readLine()) != null) {
				fullError += line;
			}

			return new ResponseEntity<String>(fullError, HttpStatus.BAD_REQUEST);
		}

		builder = new ProcessBuilder("\"..\\FPGA_LOAC_UFCG_Backend\\a.exe\"").redirectError(new File("error.txt"))
				.redirectOutput(new File("output.txt"));

		p = builder.start();

		boolean finished = p.waitFor(2, TimeUnit.SECONDS);
		if (!finished) {
			p.destroyForcibly();
			return new ResponseEntity<String>("Não duvido mais do que já suponho...", HttpStatus.REQUEST_TIMEOUT);
		}

		File file = new File("output.txt");
		FileInputStream fis = new FileInputStream(file);
		byte[] data = new byte[(int) file.length()];
		fis.read(data);
		fis.close();

		String programOutput = new String(data, "UTF-8");
		String[] slpp = programOutput.split("\n");

		HashMap<String, String> hashMap = new HashMap<>();
		for (int i = 0; i < slpp.length; i++) {
			String[] spl = slpp[i].split(":");
			hashMap.put(spl[0], spl[1]);
		}

		return new ResponseEntity<String>(hashMap.toString(), HttpStatus.OK);
	}

}