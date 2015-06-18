#include "Shape.h"


Shape::Shape(void)
{
}


Shape::~Shape(void)
{
}

int Shape::draw(int position){
	return 0;
}

bool Shape::hasColided(Airplane plane){
	return false;
}

int Shape::getBottomPosition(){
	return 0;
}

bool Shape::bulletHasCollided(Bullet * bullet){
	return false;
}

void Shape::setDestroyed(){
	return;
}