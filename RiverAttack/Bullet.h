#pragma once
#include <GL/glut.h>
class Bullet
{
public:
	Bullet(void);
	~Bullet(void);
	Bullet(int windowHeight, int windowWidth);
	void shoot();
	void draw();
	int getXposition();
	int getYPosition();
	int getTopPosition();
	void setXPosition(int x);
	void reset();
	bool isShooting();
	int getSize();
private:
	int yPosition;
	int xPosition;
	int size;
	int windowHeight;
	int windowWidth;
	bool shooting;
	bool isOutOfScreen();
};

