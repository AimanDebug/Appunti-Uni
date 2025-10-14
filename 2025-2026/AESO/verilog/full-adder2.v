module fa(input x, input y, input r, output c, output z)
	assign c = (not(x) && not(y) && rin) || (not(x) && y && not(r)) ||
		(x && not(y) && not(r)) || (x && y & rin);

	assign c = (not(x) && y && r) || (x && not(y) && r) ||
		(x && y && not(rin)) || (x && y && r);
endmodule

module fa(input [N-1:0]x, input [N-1:0]y, input rin, output c, output [N-1:0]z)
	parameter N = 8;

	genvar		i;
	wire [N-1:0]	rout;

	fa fa0(c[0], z[0], rin, rout[0], z[0]);
	generate
		for (i = 1; i < N; ++i)

endmodule
	
