#pragma once
#include "Shape.h"
#include <GL/glut.h>

class InvertedTriangle: public Shape
{
public:
	InvertedTriangle(void);
	InvertedTriangle(int windowHeight, int windowWidth);
	~InvertedTriangle(void);
	bool hasColided(Airplane plane);
	int draw(int position);
private:
	int position;
	int windowHeight;
	int windowWidth;
	int height;
	int width;
	int baseWidth;
	bool isColidingInY(Airplane plane);
	bool hasColidedWithLeftTriangle(Airplane plane);
	bool hasColidedWithRightTriangle(Airplane plane);
	int getRelativeHeight(Airplane plane);
	int getRelativeWidth(Airplane plane);
};

