#pragma once
#include "Airplane.h"
#include "Map.h"
class Colision
{
public:
	Colision(Airplane *plane, Map *map);
	~Colision(void);
	bool hasColided();
private:
	Airplane *plane;
	Map *map;
};

