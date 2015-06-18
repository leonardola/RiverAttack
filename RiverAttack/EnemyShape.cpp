#include "EnemyShape.h"


EnemyShape::EnemyShape(void)
{
}


EnemyShape::~EnemyShape(void)
{
}


bool EnemyShape::bulletHasCollided(Bullet * bullet){
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

bool EnemyShape::bulletIsCollidingInXPosition(Bullet * bullet){
	if(!this->bulletIsToTheLeft(bullet) && !this->bulletIsToTheRight(bullet) ){
		return true;
	}
	return false;
}

bool EnemyShape::bulletIsToTheLeft(Bullet * bullet){
	return bullet->getXposition() + bullet->getSize() < this->xPosition - this->width;
}

bool EnemyShape::bulletIsToTheRight(Bullet * bullet){
	return bullet->getXposition() - bullet->getSize() > this->xPosition + this->width;
}


int EnemyShape::getBottomPosition(){
	return this->yPosition - this->height + this->position;
}


bool EnemyShape::goneOutOfScreen(){
	return this->yPosition + this->height + this->position < 0;
}

void EnemyShape::setXPosition(int xPosition){
	this->xPosition = xPosition;
}

void EnemyShape::setYPosition(int yPosition){
	this->yPosition = yPosition;
}

void EnemyShape::setDestroyed(){
	this->destroyed = true;
}