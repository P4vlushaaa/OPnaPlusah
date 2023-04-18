#include <cmath>
#include <iostream>
#include "circle.hh"

namespace figure {
    circle::circle(float a_x, float a_y, float b_x, float b_y) {
        this->a.x = a_x;
        this->a.y = a_y;
        this->b.x = b_x;
        this->b.y = b_y;

    }

    float circle::square() {
        return 3.14 * (sqrtf((a.y - a.x) * (a.y - a.x) - ((b.y - b.x) * (b.y - b.x))) * (sqrtf((a.y - a.x) * (a.y - a.x) - ((b.y - b.x) * (b.y - b.x)))));
    }

    float circle::perimeter() {
        return 3.14 * (sqrtf((a.y - a.x) * (a.y - a.x) - ((b.y - b.x) * (b.y - b.x))));
    }

    void circle::draw() {
        printf("Square = %f\nPerimeter = %f\n", square(), perimeter());
    }

    float circle::mass() {
        return m;
    }

    bool circle::operator==(IPhysObject &ob) const {
        return (m == ob.mass());
    }

    bool circle::operator<(IPhysObject &ob) const {
        return (m < ob.mass());
    }

    Vector2D circle::position() {
        auto center = new Vector2D();
        center->x = a.x;
        center->y = a.y;
        return *center;
    }

    unsigned int circle::size() {
        return sizeof(circle);
    }

    const char *circle::classname() {
        return "circle";
    }
}