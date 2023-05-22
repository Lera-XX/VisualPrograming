#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

const double NOVOSIBIRSK_MIN_X = 54.6961;
const double NOVOSIBIRSK_MAX_X = 55.2855;
const double NOVOSIBIRSK_MIN_Y = 82.7316;
const double NOVOSIBIRSK_MAX_Y = 83.2245;

class Coordinates {
public:
    Coordinates(double x = 0.0, double y = 0.0)
        : x_(x), y_(y)
    {}

    double getX() const {
        return x_;
    }

    double getY() const {
        return y_;
    }

    void setX(double x) {
        x_ = x;
    }

    void setY(double y) {
        y_ = y;
    }

private:
    double x_;
    double y_;
};


class Object {
public:
    Object(const Coordinates& start = Coordinates(0.0, 0.0))
        : current_position_(start), path_(new Coordinates[1]), path_length_(1)
    {
        path_[0] = start;
    }

    ~Object() {
        delete[] path_;
    }

    const Coordinates& getCurrentPosition() const {
        return current_position_;
    }

    const Coordinates* getPath() const {
        return path_;
    }

    int getPathLength() const {
        return path_length_;
    }

    void randomWalk() {
        double dx, dy;
        do {
            dx = random_double(NOVOSIBIRSK_MIN_X, NOVOSIBIRSK_MAX_X);
            dy = random_double(NOVOSIBIRSK_MIN_Y, NOVOSIBIRSK_MAX_Y);
        } while (dx == current_position_.getX() && dy == current_position_.getY());

        double new_x = dx;
        double new_y = dy;

       
        if (isInsideNovosibirskRegion(new_x, new_y)) {
            current_position_.setX(new_x);
            current_position_.setY(new_y);

            Coordinates* new_path = new Coordinates[path_length_ + 1];
            for (int i = 0; i < path_length_; i++) {
                new_path[i] = path_[i];
            }
            new_path[path_length_] = current_position_;

            delete[] path_;
            path_ = new_path;
            path_length_++;
        }
    }

    double distanceTo(const Coordinates& target) const {
        double dx = current_position_.getX() - target.getX();
        double dy = current_position_.getY() - target.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    double convertToLatitude() const {
        return current_position_.getX() * 180.0 / M_PI;
    }

    double convertToLongitude() const {
        return current_position_.getY() * 180.0 / M_PI;
    }

private:
    Coordinates current_position_;
    Coordinates* path_;
    int path_length_;

    bool isInsideNovosibirskRegion(double x, double y) const {
        return x >= NOVOSIBIRSK_MIN_X && x <= NOVOSIBIRSK_MAX_X && y >= NOVOSIBIRSK_MIN_Y && y <= NOVOSIBIRSK_MAX_Y;
    }

    double random_double(double min, double max) {
        return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
    }
};


class UserEquipment : public Object {
public:
    UserEquipment(const Coordinates& start = Coordinates(0.0, 0.0))
        : Object(start)
    {}

    void moveObject() {
        randomWalk();
    }
};

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));

    UserEquipment userEquipment;
    for (int i = 0; i < 10; i++) {
        userEquipment.moveObject();
        std::cout << "Current Position: (" << userEquipment.getCurrentPosition().getX() << ", " << userEquipment.getCurrentPosition().getY() << ")\n";
        std::cout << "Latitude: " << userEquipment.convertToLatitude() << "\n";
        std::cout << "Longitude: " << userEquipment.convertToLongitude() << "\n\n";
    }

    const Coordinates* path = userEquipment.getPath();
    int path_length = userEquipment.getPathLength();

    std::cout << "Path:\n";
    for (int i = 0; i < path_length; i++) {
        std::cout << "(" << path[i].getX() << ", " << path[i].getY() << ")\n";
    }

    return 0;
}
