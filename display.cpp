#include "display.hpp"

Display::Display() : Score() {
	colors = new Colors[number_of_cells];
	for (int i = 0; i < number_of_points; i++)
		colors[i] = Colors();
	gradient = new Color[number_of_cells];
}

void Display::draw_rect(Color color, SDL_Rect rect) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
}

void Display::draw_head(Color color, SDL_Rect rect) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Display::generate_gradient() {
	for (int i = 0; i < number_of_points - 1; i++)
		colors[i] = colors[i + 1];
	colors[number_of_points - 1] = Colors();
	Colors col = colors[0];
	gradient[0] = col.starting;
	int step = 15;
	if(length > 10)
		 step = 200 / length + 1;
	for (int i = 1; i < length; i++) 
		gradient[i] = col.next_color(gradient[i - 1], step);

}

void Display::extend_gradient() {
	Colors col = colors[0];
	int step = 200 / length + 1;

	for (int i = 1; i < length; i++)
		gradient[i] = col.next_color(gradient[i - 1], step);
}

void Display::draw_starting_points() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (int i = 0; i < number_of_points; i++) {
		SDL_Rect p = point_to_rect(points[i]);
		draw_head(colors[i].starting, p);
		SDL_Delay(400);
		SDL_RenderPresent(renderer);
	}
	SDL_Delay(300);
	
}

void Display::draw() {
	if (pause == true) return;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	if(score_a_point())
		generate_gradient();

	draw_head(gradient[0], position[0]);
	for (int i = 1; i < length; i++) 
		draw_rect(gradient[i], position[i]);


	for (int i = 0; i < number_of_points; i++) {
		SDL_Rect p = point_to_rect(points[i]);
		draw_head(colors[i].starting, p);
	}

	SDL_RenderPresent(renderer);
}


void Display::kill() {
	running = false;

	int duration_of_death = 300;
	int step_red = gradient[0].red / duration_of_death + 1;
	int step_green = gradient[0].green / duration_of_death + 1;
	int step_blue = gradient[0].blue / duration_of_death + 1;
	for (int j = 0; j < duration_of_death; j++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		gradient[0].darken(step_red, step_green, step_blue);
		for (int i = 0; i < length; i++) {
			gradient[i] = gradient[0];
			draw_rect(gradient[i], position[i]);
		}
		SDL_RenderPresent(renderer);
		if (gradient[0].is_black() == false)
			SDL_Delay(5);
	}
}


SDL_Rect Display::point_to_rect(Point point) {
	SDL_Rect p;
	p.x = point.get_x();
	p.y = point.get_y();
	p.w = p.h = cell_height;
	return p;
}

Display::~Display() {
	free(gradient);
	free(position);
	free(colors);
	free(points);
	end(EXIT_SUCCESS);
}