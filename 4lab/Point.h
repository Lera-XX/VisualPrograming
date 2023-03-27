#ifndef POINT_H
#define POINT_H

class Point {
public:
    explicit Point(int x = 0, int y = 0);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

private:
    int x_;
    int y_;
};

#endif // POINT_H
