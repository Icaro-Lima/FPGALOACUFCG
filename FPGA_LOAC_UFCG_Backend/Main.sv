module Main();

logic SWI[7:0], LED[7:0], SEG[7:0];

initial begin
  for (int a = 0; a < 2; a++) begin
    for (int b = 0; b < 2; b++) begin
      for (int c = 0; c < 2; c++) begin
        for (int d = 0; d < 2; d++) begin
          for (int e = 0; e < 2; e++) begin
            for (int f = 0; f < 2; f++) begin
              for (int g = 0; g < 2; g++) begin
                for (int h = 0; h < 2; h++) begin
                  SWI = { a, b, c, d, e, f, g, h };

                  //////////////////////////////////
                  LED[0] = SWI[0] & SWI[1];
                  LED[1] = SWI[0] | SWI[1];
                  //////////////////////////////////

                  $display(SWI[0], SWI[1], SWI[2], SWI[3], SWI[4], SWI[5], SWI[6], SWI[7], ":", LED[0], LED[1], LED[2], LED[3], LED[4], LED[5], LED[6], LED[7], SEG[0], SEG[1], SEG[2], SEG[3], SEG[4], SEG[5], SEG[6], SEG[7]);
                end
              end
            end
          end
        end
      end
    end
  end
end

endmodule
