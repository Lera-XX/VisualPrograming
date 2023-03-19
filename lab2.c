#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Главная функция
int main() {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));

    // Создаем объект Movement
    struct Movement my_object;
    my_object.position.x = random_int(0, 999);
    my_object.position.y = random_int(0, 999);
    my_object.path = NULL;
    my_object.path_length = 0;

    // Проводим 100 шагов движения объекта
    for (int i = 0; i < 100; i++) {
        random_walk(&my_object);
    }

    // Выводим координаты всех пройденных точек
    for (int i = 0; i < my_object.path_length; i++) {
        printf("(%d, %d)\n", my_object.path[i].x, my_object.path[i].y);
    }

    // Освобождаем память, выделенную под массив path
    free(my_object.path);

    return 0;
}
