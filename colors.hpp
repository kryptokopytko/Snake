#ifndef COLORS
#define COLORS

#include "color.hpp"

class Colors {
public:
	Color starting;
	Color darkest;
	Color brightest;
	bool red_direction, blue_direction, green_direction; // false for down, true for up
	int changing_one; // 0 red, 1 green, 2 blue;

	Colors();
	Color next_color(Color previous, int step);
};



#endif