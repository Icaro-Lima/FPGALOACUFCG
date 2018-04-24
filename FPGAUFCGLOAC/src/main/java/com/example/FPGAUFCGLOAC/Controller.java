package com.example.FPGAUFCGLOAC;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {

	@RequestMapping(value = "/compile")
	public synchronized String someMethod(@RequestParam("code") String code) throws InterruptedException, IOException {

		System.out.println("Chegou!");
		
		// Lendo e substituindo no Template.
		File file = new File(
				"C:\\Users\\Lenovo\\Documents\\Unity\\FPGA_LOAC_UFCG\\FPGA_LOAC_UFCG_Backend\\Template.sv");
		FileInputStream fis = new FileInputStream(file);
		byte[] data = new byte[(int) file.length()];
		fis.read(data);
		fis.close();

		String templateReplaced = new String(data, "UTF-8");

		templateReplaced = templateReplaced.replace("CODEHERE", code);
		// End.

		// Escrevendo no Main.sv.
		PrintWriter writer = new PrintWriter(
				"C:\\Users\\Lenovo\\Documents\\Unity\\FPGA_LOAC_UFCG\\FPGA_LOAC_UFCG_Backend\\Main.sv", "UTF-8");
		writer.print(templateReplaced);
		writer.close();
		// End.

		ProcessBuilder builder = new ProcessBuilder("cmd.exe", "/c",
				"cd \"C:\\Users\\Lenovo\\Documents\\Unity\\FPGA_LOAC_UFCG\\FPGA_LOAC_UFCG_Backend\" && verilator -cc Main.sv");

		Process p = builder.start();
		BufferedReader err = new BufferedReader(new InputStreamReader(p.getErrorStream()));

		String line;
		if ((line = err.readLine()) != null && line.startsWith("%Error")) {
			String fullError = line;
			while ((line = err.readLine()) != null) {
				fullError += line;
			}

			System.out.println(fullError);
			return "Error:\n" + fullError;
		}
		
		builder = new ProcessBuilder("cmd.exe", "/c",
				"cd \"C:\\Users\\Lenovo\\Documents\\Unity\\FPGA_LOAC_UFCG\\FPGA_LOAC_UFCG_Backend\" && g++ -I\"C:\\Program Files (x86)\\verilator-3.841\\include\" -I\"obj_dir\" \"C:\\Program Files (x86)\\verilator-3.841\\include\\verilated.cpp\" obj_dir/VMain__Syms.cpp  obj_dir/VMain.cpp Main.cpp");

		p = builder.start();
		err = new BufferedReader(new InputStreamReader(p.getErrorStream()));

		if ((line = err.readLine()) != null) {
			String fullError = line;
			while ((line = err.readLine()) != null) {
				fullError += line;
			}

			System.out.println(fullError);
			return "Error:\n" + fullError;
		}

		builder = new ProcessBuilder("cmd.exe", "/c",
				"cd \"C:\\Users\\Lenovo\\Documents\\Unity\\FPGA_LOAC_UFCG\\FPGA_LOAC_UFCG_Backend\" && a.exe");

		p = builder.start();
		BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()));
		
		HashMap<String, String> hashMap = new HashMap<>();
		while ((line = r.readLine()) != null) {
			String[] spl = line.split(":");
			hashMap.put(spl[0], spl[1]);
		}

		System.out.println(hashMap);
		return hashMap.toString();
	}

}