#include <iostream>
#include <SDL.h>
#include "display.hpp"
#include "window.hpp"
#include <ctime> 
#include "point.hpp"

int main(int argc, char* argv[]) {
	srand((unsigned)time(0));
	Display a = Display();
	a.start_window();
	a.starting_screen();
	while (a.restart) {
		a.start();
		a.generate_gradient();
		a.generate_points();
		a.change_score();
		a.draw_starting_points();
		while (a.running) {
			a.draw();
			a.take_input();
			a.move();
			if (a.is_snake_hurt()) 
				a.kill();
			SDL_Delay(70);
		}
		a.restart_screen();
	}


	return 0;
}



