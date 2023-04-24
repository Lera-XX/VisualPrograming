#ifndef OBJECT_H
#define OBJECT_H

#include "coordinates.h"

class Object {
public:
    Object(int start_x = 0, int start_y = 0);
    ~Object();
    const Coordinates& getCurrentPosition() const;
    const Coordinates* getPath() const;
    int getPathLength() const;
    void randomWalk();
    double distanceTo(const Coordinates& target) const;

private:
    Coordinates current_position_;
    Coordinates* path_;
    int path_length_;
};

#endif 
