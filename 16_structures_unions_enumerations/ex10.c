#include <stdbool.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

// a
int compute_area(struct rectangle r) {
    int width, height;
    width = r.lower_right.x - r.upper_left.x;
    height = r.upper_left.y - r.lower_right.y;
    return width * height;
}

// b
struct point get_center(struct rectangle r) {
    return (struct point) {
        .x = (int) ((r.lower_right.x - r.upper_left.x) / 2),
        .y = (int) ((r.upper_left.y - r.lower_right.y) / 2),
    };
}

// c
struct rectangle move(struct rectangle r, int x, int y) {
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.x += x;
    r.lower_right.y += y;
    return r;
}

// d
bool is_inside(struct rectangle r, struct point p) {
    return p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
        p.y >= r.lower_right.y  && p.y <= r.upper_left.y;
}
