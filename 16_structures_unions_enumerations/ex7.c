// a
typedef struct { int numerator, denominator; } Fracture_t;

int gcd(int m, int n) {
    int remainder;
    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    return m;
}

Fracture_t reduce_fraction(Fracture_t f) {
    int divisor = gcd(f.numerator, f.denominator);
    return reduce_fraction((Fracture_t) {
        .numerator = f.numerator / divisor,
        .denominator = f.denominator / divisor,
    });
}

Fracture_t add_fractions(Fracture_t f1, Fracture_t f2) {
    return reduce_fraction((Fracture_t) {
        .numerator = f1.numerator + f2.numerator,
        .denominator = f1.denominator + f2.denominator,
    });
}

Fracture_t sub_fractions(Fracture_t f1, Fracture_t f2) {
    return reduce_fraction((Fracture_t) {
        .numerator = f1.numerator - f2.numerator,
        .denominator = f1.denominator - f2.denominator,
    });
}

Fracture_t mul_fractions(Fracture_t f1, Fracture_t f2) {
    return reduce_fraction((Fracture_t) {
        .numerator = f1.numerator * f2.numerator,
        .denominator = f1.denominator * f2.denominator,
    });
}

Fracture_t div_fractions(Fracture_t f1, Fracture_t f2) {
    return reduce_fraction((Fracture_t) {
        .numerator = f1.numerator * f2.denominator,
        .denominator = f1.denominator * f2.numerator,
    });
}
