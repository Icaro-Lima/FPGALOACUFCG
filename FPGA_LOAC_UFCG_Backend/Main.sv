module Main(
input logic SWI[7:0],
output logic LED[7:0],
output logic SEG[7:0]
);

always_comb SEG[0] <= SWI[0];

endmodule
