#include "Boat.h"


Boat::Boat(void)
{
}


Boat::~Boat(void)
{
}

Boat::Boat(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->height = 50;
	this->width = 50;
	this->destroyed = false;
	this->yPosition = 400;
	this->xPosition = 0;
	this->position = 0;
}

int Boat::draw(int position){

	if(this->destroyed){
		return position;
	}

	if(this->goneOutOfScreen()){
		this->setDestroyed();
		return position; 	
	}

	this->position = position; 
	glBegin(GL_POLYGON);
		glColor3f(0.0 , 0.7, 0.0); //cor
		glVertex2f(-this->width + this->xPosition, this->yPosition + this->height + position);
		glVertex2f(this->width + this->xPosition, this->yPosition + this->height + position);
		glVertex2f(this->width + this->xPosition, this->yPosition - this->height + position);
		glVertex2f(-this->width + this->xPosition, this->yPosition - this->height + position);
	glEnd();

	return position;
}