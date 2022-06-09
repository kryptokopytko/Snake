#include "window.hpp"

Window::Window() {
    screen_height = 450;
    screen_width = 600;
    cell_height = 30;
    number_of_cells = (screen_height * screen_width) / (cell_height * cell_height);
    restart = true;
}

Window::Window(int height, int width, int cell) {
    screen_height = height;
    screen_width = width;
    cell_height = cell;
    number_of_cells = (screen_height * screen_width) / (cell_height * cell_height);
    restart = true;
}

void Window::end(int exit_code)
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    exit(exit_code);
}

void Window::start_window()
{
    try {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            throw "error: failed to initiaize SDL\n";
        if (SDL_Init(IMG_INIT_JPG) < 0)
            throw "error: failed to initiaize SDL_image\n";

        window = SDL_CreateWindow("Snake",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screen_width,
            screen_height,
            SDL_WINDOW_SHOWN
        );
        if (!window)
            throw "error: failed to initiaize SDL window\n";

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!renderer)
            throw "error: failed to initiaize SDL renderer\n";
    }
    catch (const char* msg) {
        cerr << msg << '\n';
        end(EXIT_FAILURE);
    }
}

void Window::restart_screen() {
    restart = false;
    load_image("restart.jpg");
    for (int i = 0; i < 1000 && !restart; i++) {
        take_decision();
        SDL_Delay(10);
    }
    destroy_image();
}

void Window::load_image(const char* filename) {
    image = IMG_Load(filename);
    if (!image) {
        printf("error: failed to display image: %s\n", SDL_GetError());
        end(EXIT_FAILURE);
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        printf("error: failed to create texture: %s\n", SDL_GetError());
        end(EXIT_FAILURE);
    }
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Window::starting_screen() {
    running = false;
    load_image("start.jpg");
    
    while (!running) {
        take_decision();
        SDL_Delay(50);
    }
    destroy_image();
}

void Window::destroy_image() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}

void Window::instructions() {
    load_image("instructions.jpg");
}

void Window::take_decision() {
	SDL_Event input;
	while (SDL_PollEvent(&input)) {
		if (input.type == SDL_QUIT)
			end(EXIT_SUCCESS);
		if (input.type == SDL_KEYDOWN) {
            switch (input.key.keysym.sym) {
            case SDLK_s:
                running = true;
                break;
            case SDLK_i:
                instructions();
                break;
            case SDLK_q:
            case SDLK_n:
                end(EXIT_SUCCESS);
                break;
            case SDLK_r:
            case SDLK_y:
                restart = true;
                break;
            }
		}
	}
}

