#include "coordinates.h"

Coordinates::Coordinates(int x, int y)
    : x_(x), y_(y)
{}

int Coordinates::getX() const {
    return x_;
}

int Coordinates::getY() const {
    return y_;
}

void Coordinates::setX(int x) {
    x_ = x;
}

void Coordinates::setY(int y) {
    y_ = y;
}
