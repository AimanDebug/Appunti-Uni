module div2 (input [1:0] x, input [1:0] y, output [1:0] z, output [1:0] r);
  assign z[1] = x[1] && !y[1];
  assign z[0] = (x[1] && x[0]) || (x[0] && !y[1]) || (x[1] && !y[0]);
  assign r[1] = x[1] && !x[0] && y[1] && y[0];
  assign r[0] = (!x[1] && x[0] && y[1]) || (x[0] && !y[0]);
endmodule
