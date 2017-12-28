// a
typedef struct { double real, imaginary; } Complex;
// b
Complex ex3c1, ex3c2, ex3c3;
// c
Complex make_complex(double real, double imaginary) {
    return (Complex) { real, imaginary };
}
// d
Complex add_complex(Complex a, Complex b) {
    return (Complex) {
        a.real + b.real, a.imaginary + b.imaginary
    };
}
