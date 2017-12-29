#include <stdio.h>
#include <stdbool.h>

struct color {
    int red;
    int green;
    int blue;
};

int truncate(int x) {
    if (x < 0) {
        return 0;
    } else if (x > 255) {
        return 255;
    } else {
        return x;
    }
}

// a
struct color make_color(int red, int green, int blue) {
    return (struct color) {
        .red = truncate(red),
        .green = truncate(green),
        .blue = truncate(blue),
    };
}

// b
int getRed(struct color c) {
    return c.red;
}

// c
bool equal_color(struct color c1, struct color c2) {
    return c1.red == c2.red && c1.blue == c2.blue && c1.green == c2.green;
}

// d
int brighten_color(int c) {
    if (c == 0) {
        return 3;
    } else {
        return truncate((int) (c / 0.7));
    }
}

struct color brighter(struct color c) {
    if (equal_color(c, (struct color) { 0, 0, 0 })) {
        return (struct color) { 3, 3, 3};
    }

    return (struct color) {
        .red = brighten_color(c.red),
        .green = brighten_color(c.green),
        .blue = brighten_color(c.blue),
    };
}

// e
int darken_color(int c) {
    return truncate((int) (c * 0.7));
}

struct color darken(struct color c) {
    return (struct color) {
        .red = darken_color(c.red),
        .green = darken_color(c.green),
        .blue = darken_color(c.blue),
    };
}
