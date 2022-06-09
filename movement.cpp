#include "movement.hpp"

Movement::Movement() : Window() {
	start();
}

void Movement::start() {
	direction = Right;
	pause = false;
	running = true;
	starting_length = 5;
	length = starting_length;
	position = new SDL_Rect[number_of_cells];
	for (int i = length; i < number_of_cells; i++) {
		position[i].x = 0;
		position[i].y = 0;
		position[i].h = 0;
		position[i].w = 0;
	}
	position[0].x = 5 * cell_height;
	position[0].y = 5 * cell_height;
	position[0].w = cell_height;
	position[0].h = cell_height;
	for (int i = 1; i < length; i++) {
		position[i] = position[0];
		position[i].x -= cell_height * i;
	}
}

void Movement::move() {
	if (pause == true) return;
	if (!waiting_moves.empty()) {
		enum Direction newD = waiting_moves.front();
		direction = newD;
		waiting_moves.pop();
	}

	for (int i = length - 1; i > 0; i--) 
		position[i] = position[i - 1];
	position[0].x = (position[1].x + ((int)(direction == Right) - (int)(direction == Left)) * cell_height + screen_width) % screen_width;
	position[0].y = (position[1].y + ((int)(direction == Down) - (int)(direction == Up)) * cell_height + screen_height) % screen_height;

}

void Movement::take_input() {
	SDL_Event input;
	while (SDL_PollEvent(&input)) {
		if (input.type == SDL_QUIT)
			end(EXIT_SUCCESS);
		if (input.type == SDL_KEYDOWN) {
			switch (input.key.keysym.sym) {
			case SDLK_q:
				end(EXIT_SUCCESS);
				break;
			case SDLK_r:
				running = false;
				break;
			case SDLK_SPACE:
				pause = !pause;
				break;
			case SDLK_w:
			case SDLK_UP:
				if (direction != Down && (waiting_moves.empty() || (waiting_moves.back() != Down)))
					waiting_moves.push(Up);
				break;
			case SDLK_s:
			case SDLK_DOWN:
				if (direction != Up && (waiting_moves.empty() || (waiting_moves.back() != Up)))
					waiting_moves.push(Down);
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				if (direction != Left && (waiting_moves.empty() || (waiting_moves.back() != Left)))
					waiting_moves.push(Right);
				break;
			case SDLK_a:
			case SDLK_LEFT:
				if (direction != Right && (waiting_moves.empty() || (waiting_moves.front() != Right)))
					waiting_moves.push(Left);
				break;
			}
		} 
	}
}