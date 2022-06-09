#ifndef DISPLAY
#define DISPLAY

#include "score.hpp"
#include "colors.hpp"


class Display : public Score {
public:
	Colors* colors;
	Color* gradient;

	Display();
	~Display();
	void draw();
	void generate_gradient();
	void extend_gradient();
	void kill();
	void draw_rect(Color color, SDL_Rect rect);
	void draw_head(Color color, SDL_Rect rect);
	SDL_Rect point_to_rect(Point point);
};



#endif