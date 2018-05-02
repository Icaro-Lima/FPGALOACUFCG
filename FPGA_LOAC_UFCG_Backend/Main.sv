module Main(
  input logic [7:0] SWI,
  output logic [7:0] LED,
  output logic [7:0] SEG
);

// Seu código aqui:
always_comb begin
  SEG[1] <= SWI[1];
end


endmodule