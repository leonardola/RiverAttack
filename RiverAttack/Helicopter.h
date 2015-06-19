#pragma once
#include "BoxShape.h"

class Helicopter: public BoxShape
{
public: 
	Helicopter(void);
	~Helicopter(void);
	Helicopter(int windowHeight, int windowWidth);
	int draw(int position);
};

