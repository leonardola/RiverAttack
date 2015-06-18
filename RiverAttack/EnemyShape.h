#pragma once
#include "Bullet.h"
#include "Airplane.h"
class EnemyShape
{
public:
	EnemyShape(void);
	virtual ~EnemyShape(void);
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

