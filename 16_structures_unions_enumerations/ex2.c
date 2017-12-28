// Ex 2. (a)
struct { double real, imaginary; } c1_a, c2_a, c3_a;
// Ex 2. (b)
struct { double real, imaginary; } c1 = { 0.0, 1.0 }, c2 = { 1.0, 0.0 }, c3;
// Ex 2. (c)
c1 = c2;
// Ex 2. (d)
c3.real = c1.real + c2.real;
c3.imaginary = c1.imaginary + c2.imaginary;
