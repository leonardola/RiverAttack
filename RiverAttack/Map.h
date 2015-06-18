#pragma once
#include "Blocks.h"

class Map
{
public:
	Map(void);
	Map(int windowHeight, int windowWidth);
	~Map(void);
	void drawMap(int initial);
	Blocks getFirstBlock();
	Blocks getSecondBlock();
private:
	Blocks listOfBlocks[100];
	int initialPoint;
	int windowHeight;
	int windowWidth;
	int traveledDistance;
	int sizeOfMap;
	int firstElement;
	bool isFirstElement(int initialPosition);
	void updateMap();
	bool firstObjectIsOutOfScreen();
	void removeFirstObject();
	void arrayShift();
};

