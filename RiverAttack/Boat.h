#pragma once
#include "BoxShape.h"
#include "Airplane.h"
#include <GL/glut.h>

class Boat: public BoxShape
{
public:
	Boat(void);
	Boat(int windowHeight, int windowWidth);
	~Boat(void);
	bool bulletHasCollided(Bullet * bullet);
	int draw(int position);		
};

