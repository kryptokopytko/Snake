#ifndef POINT
#define POINT

#include <SDL.h>
#include <iostream>
#include <cstdlib> 

using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    bool hit(int x1, int y1);
    Point(int cell_height, int screen_width, int screen_height);
    Point();
    Point(int sx, int sy, int cell_height, int screen_width, int screen_height);
    int get_x() { return x; }
    int get_y() { return y; }
    void printPoint();
};


#endif