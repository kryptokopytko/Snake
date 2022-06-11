#include "score.hpp"

Score::Score() : Movement() {
	points = new Point[number_of_points];
	generate_points();
}

Point Score::generate_point() {
	Point point;
	bool found = 0;
	while (!found) {
		point = Point(position[0].x, position[0].y, cell_height, screen_width, screen_height);
		found = 1;
		for (int i = 0; i < length; i++)
			if (point.hit(position[i].x, position[i].y))
				found = 0;
	}
	return point;
}

void Score::generate_points() {
	for (int i = 0; i < number_of_points; i++) {
		bool found = 0;
		while (!found) {
			found = 1;
			points[i] = generate_point();
			for (int j = 0; j < i; j++)
				if (points[j].hit(points[i].get_x(), points[i].get_y()))
					found = 0;
		}
	}
}


void Score::new_point() {
	for (int i = 0; i < number_of_points - 1; i++)
		points[i] = points[i + 1];
	bool found = 0;
	while (!found) {
		found = 1;
		points[number_of_points - 1] = generate_point();
		for (int j = 0; j < number_of_points - 1; j++)
			if (points[number_of_points - 1].hit(points[j].get_x(), points[j].get_y()))
				found = 0;
	}
}

bool Score::score_a_point() {
	if (points[0].hit(position[0].x, position[0].y)) {
		new_point();
		length++;
		change_score();
		return 1;
	}
	return 0;
}

void Score::change_score() {
	char title[200];
	int high_score = highscore();
	int score = length - starting_length;
	snprintf(title, 200, "Score: %d                                                                                             Highscore: %d", score, high_score);
	SDL_SetWindowTitle(window, title);
}

int Score::highscore() {
	string filename = "highscore.txt";
	if (player == Kasia) filename = "highscore_kasia.txt";
	if (player == Marcin) filename = "highscore_marcin.txt";

	string line;
	ifstream file(filename);
	getline(file, line);
	int highscore = std::stoi(line);
	file.close();
	
	int score = length - starting_length;
	if (highscore < score) {
		ofstream myfile;
		myfile.open(filename);
		myfile << score;
		myfile.close();
		highscore = score;
	}
	return highscore;
}

void Score::clean_highscores() {
	string filename = "highscore.txt";
	ofstream myfile;
	myfile.open(filename);
	myfile << 0;
	myfile.close();
	filename = "highscore_kasia.txt";
	myfile.open(filename);
	myfile << 0;
	myfile.close();
	filename = "highscore_marcin.txt";
	myfile.open(filename);
	myfile << 0;
	myfile.close();
}

bool Score::is_snake_hurt() {
	for (int i = 3; i < length; i++)
		if (position[0].x == position[i].x && position[0].y == position[i].y)
			return 1;
	for (int i = 1; i < number_of_points; i++)
		if (points[i].hit(position[0].x, position[0].y))
			return 1;
	return 0;
}