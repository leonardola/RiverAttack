#include "Colision.h"


Colision::Colision(Airplane * plane, Map * map){
	this->map = map;
	this->plane = plane;
}


Colision::~Colision(void)
{
}

bool Colision::hasColided(){
	return this->map->getFirstBlock().hasColided(*this->plane) || this->map->getSecondBlock().hasColided(*this->plane);
}
