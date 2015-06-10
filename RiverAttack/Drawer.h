#pragma once
#include "Blocks.h"
class Drawer
{
public:
	Drawer(int,int);
	~Drawer(void);
	void drawMap(int initialPosition);

private:
	Blocks mapBlocks[10];
	int windowHeight;
	int startingPosition;
	void createBaseMap(int windowHeight, int windowWidth);
};

