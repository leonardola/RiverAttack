#pragma once
#include "BoxShape.h"

class Bridge: public BoxShape
{
public:
	Bridge(void);
	~Bridge(void);
	Bridge(int windowHeight, int windowWidth);
	int draw(int position);
	void reset();

private:
	
};

