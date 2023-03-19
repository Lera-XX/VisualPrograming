#ifndef MOVEMENT_H
#define MOVEMENT_H

// Структура для хранения координат объекта
struct Point {
    int x;
    int y;
};

// Структура для хранения информации о движении объекта
struct Movement {
    struct Point position;      // Текущая позиция
    struct Point* path;         // Массив с координатами всех пройденных точек
    int path_length;            // Длина массива path
};

// Функция для движения объекта
void random_walk(struct Movement* movement);

#endif /* MOVEMENT_H */
