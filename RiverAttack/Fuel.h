#pragma once
#include "BoxShape.h"

class Fuel: public BoxShape
{
public:
	Fuel(void);
	~Fuel(void);
	Fuel(int windowHeight,int windowWidth);
	void reset(int position);
	int draw(int position);
private:
	int generateRandomXPosition();
};

