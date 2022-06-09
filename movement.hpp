#ifndef MOVEMENT
#define MOVEMENT

#include "window.hpp"
#include <queue>


enum Direction { Up, Right, Down, Left };

class Movement : public Window{
protected:
    
    int starting_length;
    SDL_Rect* position;
    Direction direction;
    bool pause;
    queue<Direction> waiting_moves;
public:
    int length;
    Movement();
    void move();
    void take_input();
    void start();
    
};

#endif