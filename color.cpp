#include "color.hpp"

Color::Color() {
	red = rand() % 236 + 20;
	green = rand() % 236 + 20;
	blue = rand() % 236 + 20;
}

void Color::print() {
	cout << red << ' ' << green << ' ' << blue << '\n';
}

Color Color::Darkest() {
	red = rand() % 56;
	green = rand() % 56;
	blue = rand() % 56;
	return *this;
}

Color Color::Brightest() {
	red = rand() % 56 + 200;
	green = rand() % 56 + 200;
	blue = rand() % 56 + 200;
	return *this;
}

Color Color::Starting(Color darkest, Color brightest) {
	red = rand() % (brightest.red - darkest.red) + darkest.red;
	green = rand() % (brightest.green - darkest.green) + darkest.green;
	blue = rand() % (brightest.blue - darkest.blue) + darkest.blue;
	return *this;
}

Color Color::white() {
	Color white;
	white.red = white.blue = white.green = 255;
	return white;
}

void Color::darken(int step) {
	red -= step;
	if (red < 0)
		red = 0;
	green -= step;
	if (green < 0)
		green = 0;
	blue -= step;
	if (blue < 0)
		blue = 0;
}

void Color::darken(int step_red, int step_green, int step_blue) {
	red -= step_red;
	if (red < 0)
		red = 0;
	green -= step_green;
	if (green < 0)
		green = 0;
	blue -= step_blue;
	if (blue < 0)
		blue = 0;
}

bool Color::is_black() {
	if (red == 0 && blue == 0 && green == 0)
		return true;
	return false;
}