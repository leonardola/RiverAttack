#pragma once
#include "Shape.h"
#include "Airplane.h"
class Triangle: public Shape
{
public:
	Triangle(void);
	Triangle(int windowHeight, int windowWidth);
	~Triangle(void);
	int draw(int position);
	bool hasColided(Airplane plane);
private:
	int height;
	int base;
	int windowHeight;
	int windowWidth;
	int position;
	int baseBlockWidth;
	bool hasColidedWithLeftTriangle(Airplane plane);
	int getRightTriangleX(Airplane plane);
	bool isColidingInY(Airplane plane);
	bool hasColidedWithRightTriangle(Airplane plane);
	int getLeftTriangleX(Airplane plane);
};

