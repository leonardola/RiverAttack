#pragma once
#include "Airplane.h"
#include <GL/glut.h>
class Shape
{
public:
	Shape(void);
	Shape(int windowHeight, int windowWidth);
	virtual ~Shape(void);
	virtual int draw(int position);
	virtual bool hasColided(Airplane plane);
	virtual int getBottomPosition();
	virtual bool bulletHasCollided(Bullet *bullet);
	virtual void setDestroyed();
private:
	int height;
	int width;
	int windowHeight;
	int windowWidth;
};

