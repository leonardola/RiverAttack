#pragma once
#include "EnemyShape.h"

class Helicopter: public EnemyShape
{
public: 
	Helicopter(void);
	~Helicopter(void);
	Helicopter(int windowHeight, int windowWidth);
	int draw(int position);
};

