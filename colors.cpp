#include "colors.hpp"

Colors::Colors() {
	darkest = darkest.Darkest();
	brightest = brightest.Brightest();
	starting = starting.Starting(darkest, brightest);
	red_direction = rand() % 2;
	blue_direction = rand() % 2;
	green_direction = rand() % 2;
	changing_one = rand() % 3;
}

Color Colors::next_color(Color previous, int step) {
	Color next = previous;
	switch (changing_one){
	case 0 :
		if (red_direction == 0) {
			next.red = previous.red - step;
			if (next.red < darkest.red) {
				red_direction = 1;
				next.red = previous.red + step;
				changing_one++;
			}
		}
		else {
			next.red = previous.red + step;
			if (next.red > brightest.red) {
				red_direction = 0;
				next.red = previous.red - step;
				changing_one++;
			}
		}
		break;
	case 1:
		if (green_direction == 0) {
			next.green = previous.green - step;
			if (next.green < darkest.green) {
				green_direction = 1;
				next.green = previous.green + step;
				changing_one++;
			}
		}
		else {
			next.green = previous.green + step;
			if (next.green > brightest.green) {
				green_direction = 1;
				next.green = previous.green - step;
				changing_one++;
			}
		}
		break;
	case 2:
		
		if (blue_direction == 0) {
			next.blue = previous.blue - step;
			if (next.blue < darkest.blue) {
				blue_direction = 1;
				next.blue = previous.blue + step;
				changing_one = 0;
			}
		}
		else {
			next.blue = previous.blue + step;
			if (next.blue > brightest.blue) {
				blue_direction = 0;
				next.blue = previous.blue - step;
				changing_one = 0;
			}
		}
		break;
	}
	return next;
}