#include <iostream>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "coordinates.h"

// Генератор случайных чисел в заданном диапазоне
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));

    // Создаем объект класса Object
    Coordinates start(random_int(0, 999), random_int(0, 999));
    Object my_object(start);

    // Проводим 100 шагов движения объекта
    for (int i = 0; i < 100; i++) {
        my_object.randomWalk();
    }

    // Выводим координаты всех пройденных точек
    for (const auto& point : my_object.getPath()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ")" << std::endl;
    }

    // Рассчитываем длину пройденного пути
    std::cout << "Path length: " << my_object.getPathLength() << std::endl;

    // Рассчитываем расстояние до случайной точки
    Coordinates random_point(random_int(0, 999), random_int(0, 999));
    std::cout << "Distance to random point (" << random_point.getX() << ", " << random_point.getY() << "): "
              << my_object.distanceTo(random_point) << std::endl;

    return 0;
}
