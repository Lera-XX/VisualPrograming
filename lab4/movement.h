#ifndef MOVEMENT_H
#define MOVEMENT_H

// Структура для хранения координат объекта
struct Point {
    int x;
    int y;
};

// Структура для хранения информации о движении объекта
struct Movement {
private:
    Point position;      // Текущая позиция
    Point* path;         // Массив с координатами всех пройденных точек
    int path_length;     // Длина массива path
public:
    Movement() : path_length(0), path(nullptr) {}
    ~Movement() { free(path); }
    void random_walk();
    void print_path() const;
};

#endif /* MOVEMENT_H */
