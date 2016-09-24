#include "BoxShape.h"


BoxShape::BoxShape(void)
{
}


BoxShape::~BoxShape(void)
{
}

bool BoxShape::hasColided(Airplane plane){

	if(this->isDestroyed() || ! this->hasColidedInY(plane)){
		return false;
	}
	return this->hasColidedInX(plane);
}

bool BoxShape::hasColidedInY(Airplane plane){
	return plane.getSuperiorY() > this->yPosition - this->height + this->position;
}

bool BoxShape::hasColidedInX(Airplane plane){
	return !this->isOutToTheLeft(plane) && !this->isOutToTheRight(plane);
}

bool BoxShape::isOutToTheLeft(Airplane plane){
	return plane.getXPosition() + plane.getWidth() < this->xPosition - this->width;
}

bool BoxShape::isOutToTheRight(Airplane plane){
	return plane.getXPosition() - plane.getWidth() > this->xPosition + this->width;
}

bool BoxShape::bulletHasCollided(Bullet * bullet){
	if(!bullet->isShooting()){
		return false;
	}

	if(destroyed || !this->bulletIsCollidingInXPosition(bullet)){
		return false;
	}
	
	if( bullet->getTopPosition() > this->getBottomPosition()){
		bullet->reset();
		this->setDestroyed();
		return true;
	}
	return false;
}

bool BoxShape::bulletIsCollidingInXPosition(Bullet * bullet){
	if(!this->bulletIsToTheLeft(bullet) && !this->bulletIsToTheRight(bullet) ){
		return true;
	}
	return false;
}

bool BoxShape::bulletIsToTheLeft(Bullet * bullet){
	return bullet->getXposition() + bullet->getSize() < this->xPosition - this->width;
}

bool BoxShape::bulletIsToTheRight(Bullet * bullet){
	return bullet->getXposition() - bullet->getSize() > this->xPosition + this->width;
}


int BoxShape::getBottomPosition(){
	return this->yPosition - this->height + this->position;
}


bool BoxShape::goneOutOfScreen(){
	return this->yPosition + this->height + this->position < 0;
}

void BoxShape::setXPosition(int xPosition){
	this->xPosition = xPosition;
}

void BoxShape::setYPosition(int yPosition){
	this->yPosition = yPosition;
}

void BoxShape::setDestroyed(){
	this->destroyed = true;
}

int BoxShape::draw(int position){
	return position;
}

bool BoxShape::isDestroyed(){
	return this->destroyed;
}