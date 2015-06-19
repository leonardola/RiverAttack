#pragma once
#include <GL/glut.h>
#include "Bullet.h"
#include <stdio.h>
class Airplane
{
public:
	Airplane(void);
	Airplane(int windowHeight, int windowWidth);
	~Airplane(void);
	int getXPosition();
	int getYPosition();
	void drawPlane();
	void getKeyboardAction();
	void drawBullet(int val);
	int getWidth();
	int getHeight();
	int getSuperiorY();
	int getInferiorY();
	void explode();
	Bullet * getBullet();
	int getFuelPercentage();
	void useFuel();
	void refuel();
private:
	int windowHeight;
	int windowWidth;
	int xPosition;
	int yPosition;
	int xSpeed;
	int width;
	int height;
	int fuelAmount;
	Bullet bullet;
	void shoot();

};

