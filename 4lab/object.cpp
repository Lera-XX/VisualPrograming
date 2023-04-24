#include "object.h"
#include <cstdlib>
#include <cmath>

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

Object::Object(int start_x, int start_y)
    : current_position_(start_x, start_y), path_(nullptr), path_length_(0)
{}

Object::~Object() {
    delete[] path_;
}

const Coordinates& Object::getCurrentPosition() const {
    return current_position_;
}

const Coordinates* Object::getPath() const {
    return path_;
}

int Object::getPathLength() const {
    return path_length_;
}

void Object::randomWalk() {
    int dx, dy;
    do {
        dx = random_int(-1, 1);
        dy = random_int(-1, 1);
    } while (dx == 0 && dy == 0);

    current_position_.setX(current_position_.getX() + dx);
    current_position_.setY(current_position_.getY() + dy);

    path_length_++;
    Coordinates* new_path = new Coordinates[path_length_];
    for (int i = 0; i < path_length_ - 1; i++) {
        new_path[i] = path_[i];
    }
    new_path[path_length_ - 1] = current_position_;
    delete[] path_;
    path_ = new_path;
}

double Object::distanceTo(const Coordinates& target) const {
    double dx = current_position_.getX() - target.getX();
    double dy = current_position_.getY() - target.getY();
    return sqrt(dx * dx + dy * dy);
}
