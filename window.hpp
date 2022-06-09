#ifndef WINDOW
#define WINDOW

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

class Window {
protected:
    int screen_height;
    int screen_width;
    int cell_height;
    int number_of_cells;
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Surface* image;
    SDL_Texture* texture;
    
public:
    bool restart;
    bool running;

    Window();
    Window(int height, int width, int cell);
    void end(int exit_code);
    void start_window();
    void restart_screen();
    void take_decision();
    void starting_screen();
    void instructions();
    void load_image(const char* filename);
    void destroy_image();
};

#endif