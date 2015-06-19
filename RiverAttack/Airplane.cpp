#include "Airplane.h"

Airplane::Airplane(void)
{
}

Airplane::Airplane(int windowHeight, int windowWidth)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->xSpeed = 5;
	this->width = 50;
	this->height = 100;
	this->xPosition = 0;
	this->yPosition = 100;
	this->fuelAmount = this->windowHeight*2;

	Bullet bullet(windowHeight,windowWidth);
	this->bullet = bullet;
}


Airplane::~Airplane(void)
{
}

void Airplane::drawPlane(){
	glBegin(GL_POLYGON);
		glColor3f(0.0 , 0.7, 0.0); //cor
		glVertex2f(-this->width + this->xPosition, this->yPosition + this->height);
		glVertex2f(this->width + this->xPosition, this->yPosition + this->height);
		glVertex2f(this->width + this->xPosition, -this->yPosition);
		glVertex2f(-this->width + this->xPosition, -this->yPosition);
	glEnd();
	
	this->bullet.draw();

}

void Airplane::getKeyboardAction(){

	if(GetAsyncKeyState(0x41)){//A

		this->xPosition -= this->xSpeed;

	}

	if(GetAsyncKeyState(0x44)){//D

		this->xPosition += this->xSpeed;

	}

	if(GetAsyncKeyState(VK_LEFT)){//Esquerda

		this->xPosition -= this->xSpeed;

	}

	if(GetAsyncKeyState(VK_RIGHT)){//Direita
		this->xPosition += this->xSpeed;
	}
	
	if(GetAsyncKeyState(VK_SPACE)){
		this->shoot();
	}
}

int Airplane::getXPosition(){
	return this->xPosition;
}

int Airplane::getYPosition(){
	return this->yPosition;
}
 
int Airplane::getWidth(){
	return this->width;
}

int Airplane::getHeight(){
	return this->height;
}

int Airplane::getSuperiorY(){
	return this->yPosition + this->height;
}

int Airplane::getInferiorY(){
	return this->yPosition - this->height;
}

void Airplane::explode(){

	glBegin(GL_POLYGON);
		glColor3f(0.0 , 0.0, 0.0); //cor
		glVertex2f(-this->width + this->xPosition, this->yPosition + this->height);
		glVertex2f(this->width + this->xPosition, this->yPosition + this->height);
		glVertex2f(this->width + this->xPosition, -this->yPosition);
		glVertex2f(-this->width + this->xPosition, -this->yPosition);	
	glEnd();

}

void Airplane::shoot(){
	this->bullet.setXPosition(this->xPosition);
	this->bullet.shoot();
}

Bullet * Airplane::getBullet(){
	return &this->bullet;
}

int Airplane::getFuelPercentage(){
	return (this->fuelAmount*100)/(this->windowHeight*2);
}

void Airplane::useFuel(){
	if(this->fuelAmount <= 0){
		this->explode();
		return;
	}

	this->fuelAmount--;
	printf("\ncombustivel %i:",this->getFuelPercentage());
}

void Airplane::refuel(){
	this->fuelAmount = this->windowHeight * 2;
}