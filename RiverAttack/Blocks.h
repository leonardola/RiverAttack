#pragma once

class Blocks
{
public:
	int windowHeight, windowWidth;
	Blocks(int windowHeight, int windowWidth);
	~Blocks(void);
	int drawBlock(int initialPosition);
private:
	int getRandomBlock();
	int objectType;
	int drawBase(int initial);
	int drawTriangle(int initial);
}; 