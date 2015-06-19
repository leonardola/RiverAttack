#pragma once
#include <GL/glut.h>
class Score
{
public:
	Score(void);
	~Score(void);
	Score(int windowHeight, int windowWidth);
	void addScore();
	int getScore();
	void draw();
	void setFuelAmount(int fuelAmount);
private: 
	int windowHeight;
	int windowWidth;
	int score;
	int fuelAmountPercentage;
	int getRelativeSize(int size);
};

