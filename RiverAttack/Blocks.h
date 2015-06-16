#pragma once
#include "Airplane.h"
#include "Shape.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <random>
#include "Base.h"
#include "Triangle.h"
#include "InvertedTriangle.h"

class Blocks
{
public:
	Blocks(void);
	Blocks(int windowHeight, int windowWidth);
	~Blocks(void);
	int drawBlock(int initialPosition);
	int getBlockHeight();
	bool hasColided(Airplane plane);
private:
	Shape *block;
	void getRandomBlock();
	int windowHeight;
	int windowWidth;
}; 

