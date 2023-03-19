#include "movement.h"
#include <stdlib.h>
#include <time.h>

// Генератор случайных чисел
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для движения объекта
void random_walk(struct Movement* movement) {
    int dx, dy;
    do {
        // Генерируем случайное смещение в пределах [-1, 1] по осям X и Y
        dx = random_int(-1, 1);
        dy = random_int(-1, 1);
    } while (dx == 0 && dy == 0); // Проверяем, что смещение не равно нулю

    // Обновляем координаты объекта
    movement->position.x += dx;
    movement->position.y += dy;

    // Добавляем новую точку в массив path
    movement->path_length++;
    movement->path = (struct Point*)realloc(movement->path, movement->path_length * sizeof(struct Point));
    movement->path[movement->path_length - 1] = movement->position;
}

