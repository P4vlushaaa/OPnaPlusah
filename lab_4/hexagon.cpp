#include <cmath>
#include <iostream>
#include "hexagon.hh"

namespace figure {
    hexagon::hexagon(float a_x, float a_y, float b_x, float b_y) {
        this->a.x = a_x;
        this->a.y = a_y;
        this->b.x = b_x;
        this->b.y = b_y;

    }

    float hexagon::square() {
        return (3 * sqrtf(3) * sqrtf(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y))) *
                sqrtf(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)))) / 2;
    }

    float hexagon::perimeter() {
        return sqrtf(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y))) * 6;
    }

    void hexagon::draw() {
        printf("Square = %f\nPerimeter = %f\n", square(), perimeter());
    }

    float hexagon::mass() {
        return m;
    }

    bool hexagon::operator==(IPhysObject &ob) const {
        return (m == ob.mass());
    }

    bool hexagon::operator<(IPhysObject &ob) const {
        return (m < ob.mass());
    }

    Vector2D hexagon::position() {
        auto center = new Vector2D();
        center->x = sqrtf(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y))) / 2;
        center->y = (sqrtf(3) * sqrtf(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)))) / 2;
        return *center;
    }

    unsigned int hexagon::size() {
        return sizeof(hexagon);
    }

    const char *hexagon::classname() {
        return "hexagon";
    }
}