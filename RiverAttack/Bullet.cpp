#include "Bullet.h"


Bullet::Bullet(void){
}

Bullet::~Bullet(void){
}


Bullet::Bullet(int windowHeight,int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->yPosition = 200;
	this->xPosition = 0;
	this->size = 5;
	this->shooting = false;
}

void Bullet::shoot(){
	this->shooting = true;
	this->draw();
}

void Bullet::draw(){
	if(!this->shooting){
		return;
	}

	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 1.0); //cor
		glVertex2f(-this->size + this->xPosition, this->yPosition + this->size);
		glVertex2f(this->size + this->xPosition, this->yPosition + this->size);
		glVertex2f(this->size + this->xPosition, this->yPosition - this->size);
		glVertex2f(-this->size + this->xPosition, this->yPosition - this->size);
	glEnd();

	if(this->isOutOfScreen()){
		this->reset();
	}

	this->yPosition += 3;
}

bool Bullet::isOutOfScreen(){
	return this->yPosition + this->size > this->windowHeight;
}

int Bullet::getXposition(){
	return this->xPosition;
}

int Bullet::getYPosition(){
	return this->yPosition;
}

void Bullet::setXPosition(int x){
	if(!this->shooting){
		this->xPosition = x;
	}
}

int Bullet::getTopPosition(){
	return this->yPosition + this->size;
}

void Bullet::reset(){
	this->shooting = false;
	this->yPosition = 200;
}

bool Bullet::isShooting(){
	return this->shooting;
}

int Bullet::getSize(){
	return this->size;
}