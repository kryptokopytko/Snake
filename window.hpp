#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;
enum Player { Unknown, Kasia, Marcin };

class Window {
protected:
    int screen_height;
    int screen_width;
    int cell_height;
    int number_of_cells;
    int number_of_points;
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Surface* image;
    SDL_Texture* texture;
    enum Player player;
    
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
    void player_instructions();
    void load_image(const char* filename);
    void destroy_image();
};

#endif