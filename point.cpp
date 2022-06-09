#include "point.hpp"

bool Point::hit(int x1, int y1) {
    if (x == x1 && y == y1)
        return true;
    return false;
}

Point::Point(int cell_height, int screen_width, int screen_height) {
    x = ((rand() % 10000) * cell_height) % screen_width;
    y = ((rand() % 10000) * cell_height) % screen_height;
}

Point::Point(int sx, int sy, int cell_height, int screen_width, int screen_height) {
    bool found = 0;
    while (!found) {
        found = 1;
        x = ((rand() % 10000) * cell_height) % screen_width;
        y = ((rand() % 10000) * cell_height) % screen_height;
        if (sx == x || sy == y)
            found = 0;
    }
}

Point::Point() {
    x = y = 0;
}

void Point::printPoint() {
    cout << x << ' ' << y;
}

