#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "movement.h"

int main() {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));

    // Создаем объект Movement
    Movement* my_object = create_movement();

    // Проводим 100 шагов движения объекта
    for (int i = 0; i < 100; i++) {
        random_walk(my_object);
    }

    // Выводим координаты всех пройденных точек
    printf("Path:\n");
    print_path(my_object);

    // Освобождаем память, выделенную под объект Movement
    free_movement(my_object);

    return 0;
}
