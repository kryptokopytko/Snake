#ifndef SCORE
#define SCORE

#include <fstream>
#include "movement.hpp"
#include "point.hpp"


using namespace std;

class Score : public Movement {
protected:
	Point* points;
public:
	Score();
	Point generate_point();
	void generate_points();
	void new_point();
	bool score_a_point();
	int highscore();
	void change_score();
	bool is_snake_hurt();
	void clean_highscores();
};


#endif