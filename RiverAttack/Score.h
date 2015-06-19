#pragma once
#include <GL/glut.h>
#include "seteSegmentos.h"
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
	void reset();
private: 
	int windowHeight;
	int windowWidth;
	int score;
	int fuelAmountPercentage;
	int getRelativeSize(int size);
	seteSegmentos display; 
};

