#ifndef SCORE
#define SCORE

#include "movement.hpp"
#include "point.hpp"

using namespace std;

class Score : public Movement {
protected:
	const int number_of_points = 5;
	Point* points;
public:
	Score();
	Point generate_point();
	void generate_points();
	void new_point();
	bool score_a_point();
	void change_score();
	bool is_snake_hurt();
};


#endif