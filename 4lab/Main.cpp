#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Movement.h"

int main() {
    srand(time(nullptr));

    Movement my_object(random_int(0, 999), random_int(0, 999));

    for (int i = 0; i < 100; i++) {
        my_object.randomWalk();
    }

    for (int i = 0; i < my_object.getPathLength(); i++) {
        std::cout << "(" << my_object.getPath()[i].getX() << ", " << my_object.getPath()[i].getY() << ")" << std::endl;
    }

    return 0;
}
