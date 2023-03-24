#include <iostream>
#include "Head_1.hh"

Square::Square(double x, double y, double side)
        : x_(x), y_(y), side_(side) {}

double Square::area() const {
    return side_ * side_;
}

void Square::scale(double scale) {
    side_ *= scale;
}

void Square::move(double dx, double dy) {
    x_ += dx;
    y_ += dy;
}

void Square::kordi() {
    std::cout << "( " << x_ << " " << y_ << " )";
}

bool Square::operator==(const Square& other) const {
    return area() == other.area();
}

bool Square::operator!=(const Square& other) const {
    return area() != other.area();
}

bool Square::operator<(const Square& other) const {
    return area() < other.area();
}

bool Square::operator>(const Square& other) const {
    return area() > other.area();
}