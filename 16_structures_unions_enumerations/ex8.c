struct color {
    int red;
    int green;
    int blue;
};

const struct color MAGENTA_a = { 255, 0, 255 };
const struct color MAGENTA_b = { .red = 255, .blue = 255 };
