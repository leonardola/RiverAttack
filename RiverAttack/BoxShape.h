#pragma once
#include "Bullet.h"
#include "Airplane.h"
class BoxShape
{
public:
	BoxShape(void);
	virtual ~BoxShape(void);
	bool bulletHasCollided(Bullet * bullet);
	void setXPosition(int xPosition);
	void setYPosition(int yPosition);
	void setDestroyed();
	virtual int draw(int position);
	int getBottomPosition();
	bool hasColided(Airplane plane);
	bool isDestroyed();
protected:
	int height;
	int width;
	int windowHeight;
	int windowWidth;
	int yPosition;
	int xPosition;
	int position;
	bool destroyed;
	bool bulletIsCollidingInXPosition(Bullet * bullet);
	bool bulletIsToTheLeft(Bullet * bullet);
	bool bulletIsToTheRight(Bullet * bullet);
	bool goneOutOfScreen();
	bool hasColidedInY(Airplane plane);
	bool hasColidedInX(Airplane plane);
	bool isOutToTheLeft(Airplane plane);
	bool isOutToTheRight(Airplane plane);
};

