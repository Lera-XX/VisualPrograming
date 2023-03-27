#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Point.h"

class Movement {
public:
    explicit Movement(int start_x, int start_y);
    ~Movement();

    const Point& getPosition() const;
    const Point* getPath() const;
    int getPathLength() const;

    void randomWalk();

private:
    Point position;
    Point* path;
    int path_length;
};

#endif // MOVEMENT_H
