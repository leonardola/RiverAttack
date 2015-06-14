#pragma once
#include "Airplane.h"
class Blocks
{
public:
	Blocks(void);
	int windowHeight, windowWidth;
	Blocks(int windowHeight, int windowWidth);
	~Blocks(void);
	int drawBlock(int initialPosition);
	int getBlockHeight();
	bool hasColided(Airplane plane);
private:
	int objectType;
	int blockHeight;
	int drawBase(int initial);
	int drawTriangle(int initial);
	int getRandomBlock();
	bool hasColidedWithBase(Airplane plane);
	bool hasColidedWithTriangle(Airplane plane);
	bool hasColidedWithLeftBase(Airplane plane);
	bool hasColidedWithRightBase(Airplane plane);
	

}; 