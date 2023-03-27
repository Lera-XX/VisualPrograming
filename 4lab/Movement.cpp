#include "Movement.h"
#include <cstdlib>
#include <ctime>

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

Movement::Movement(int start_x, int start_y)
    : position(start_x, start_y), path(nullptr), path_length(0) {}

Movement::~Movement() {
    delete[] path;
}

const Point& Movement::getPosition() const {
    return position;
}

const Point* Movement::getPath() const {
    return path;
}

int Movement::getPathLength() const {
    return path_length;
}

void Movement::randomWalk() {
    int dx, dy;
    do {
        dx = random_int(-1, 1);
        dy = random_int(-1, 1);
    } while (dx == 0 && dy == 0);

    position.setX(position.getX() + dx);
    position.setY(position.getY() + dy);

    path_length++;
    Point* new_path = new Point[path_length];
    for (int i = 0; i < path_length - 1; i++) {
        new_path[i] = path[i];
    }
    new_path[path_length - 1] = position;
    delete[] path;
    path = new_path;
}
