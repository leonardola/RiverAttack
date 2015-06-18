#pragma once
#include"Bullet.h"

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
};

