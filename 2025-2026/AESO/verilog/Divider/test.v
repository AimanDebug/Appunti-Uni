module test;
  reg [1:0] a;
  reg [1:0] b;
  wire [1:0] q;
  wire [1:0] r;

  div2 divider (a, b, q, r);
  initial
    begin
      $dumpfile("test.vcd");
      $dumpvars;
      a = 2'b11; // 3
      b = 2'b10; // 2

      #2;

      a = 2'b10; // 2
      b = 2'b01; // 1

      #2;

      a = 2'b00;
      b = 2'b11;

      #2;

      $finish;
    end
endmodule
