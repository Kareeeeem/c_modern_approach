#include <math.h>

enum shape_kind { RECTANGLE, CIRCLE };

struct point { int x, y; };

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

double compute_area(struct shape s) {
    if (s.shape_kind == RECTANGLE) {
        return s.u.rectangle.height * s.u.rectangle.width;
    } else {
        return M_PI * s.u.circle.radius * s.u.circle.radius;
    }
}

struct shape move_shape(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;
    return s;
}

struct shape scale_shape(struct shape s, double factor) {
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.width *= factor;
        s.u.rectangle.height *= factor;
    } else {
        s.u.circle.radius *= factor;
    }
    return s;
}
