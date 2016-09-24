#include "Fuel.h"


Fuel::Fuel(void)
{
}


Fuel::~Fuel(void)
{
}

Fuel::Fuel(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->height = 50;
	this->width = 20;
	this->destroyed = true;
	this->yPosition = windowHeight + this->height;
	this->xPosition = 0;
	this->position = 0;
}

void Fuel::reset(int position){
	if(!this->destroyed){
		return;
	}

	this->xPosition = this->generateRandomXPosition();
	this->yPosition = this->windowHeight + this->height;
	this->destroyed = false;
}

int Fuel::generateRandomXPosition(){
	int random = rand() % 100;

	if(random < 33){
		return -this->windowWidth/4;
	}else if(random < 66){
		return 0;
	}else{
		return this->windowWidth/4;
	}
}

int Fuel::draw(int position){

	if(this->destroyed){
		return position;
	}

	if(this->goneOutOfScreen()){
		this->setDestroyed();
		return position; 	
	}

	this->yPosition -= 3;

	glBegin(GL_POLYGON);
		glColor3f(1.0 , 0.0, 0.0); //cor
		glVertex2f(-this->width + this->xPosition, this->yPosition + this->height);
		glVertex2f(this->width + this->xPosition, this->yPosition + this->height);
		glVertex2f(this->width + this->xPosition, this->yPosition - this->height);
		glVertex2f(-this->width + this->xPosition, this->yPosition - this->height);
	glEnd();

	return position;
}