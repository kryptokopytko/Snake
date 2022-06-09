#ifndef COLOR
#define COLOR

#include <iostream>
using namespace std;


class Color {
public:
	int red;
	int green;
	int blue;
	Color Darkest();
	Color Brightest();
	Color Starting(Color darkest, Color brightest);
	Color();
	void print();
	Color white();
	void darken(int step);
	void darken(int step_red, int step_blue, int step_green);
	bool is_black();
};

#endif