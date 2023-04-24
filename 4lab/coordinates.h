#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
public:
    Coordinates(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

private:
    int x_;
    int y_;
};

#endif // COORDINATES_H
