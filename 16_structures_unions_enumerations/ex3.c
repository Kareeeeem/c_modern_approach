// a
struct complex { double real, imaginary; };
// b
struct complex ex3c1, ex3c2, ex3c3;
// c
struct complex make_complex(double real, double imaginary) {
    return (struct complex) { real, imaginary };
}
// d
struct complex add_complex(struct complex a, struct complex b) {
    return (struct complex) {
        a.real + b.real, a.imaginary + b.imaginary
    };
}
