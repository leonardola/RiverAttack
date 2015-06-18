#include "Triangle.h"


Triangle::Triangle(void)
{
}

Triangle::Triangle(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->height = 200;
	this->base = 100;
	this->baseBlockWidth = 100;
}

Triangle::~Triangle(void)
{
}

/**
* desenha um bloco triangulo
*/
int Triangle::draw(int position){

	//esquerdo
	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(-this->windowWidth/2, 200 + position);
		glVertex2f(-this->windowWidth/2 + 200, 200 + position);
		glVertex2f(-this->windowWidth/2 + 100, position);
		glVertex2f(-this->windowWidth/2, position);
		//glVertex2f(-this->windowWidth/2 - 100, 100 + initial);
	glEnd();


	//direito
	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(this->windowWidth/2 - 200, 200 + position);
		glVertex2f(this->windowWidth/2, 200 + position);
		glVertex2f(this->windowWidth/2, position);
		glVertex2f(this->windowWidth/2 - 100, position);
		glVertex2f(this->windowWidth/2 - 100, 100 + position);
	glEnd();

	this->position = position; 

	return position + 200;
}


bool Triangle::hasColided(Airplane plane){
	if(!this->isColidingInY(plane)){
		return false;
	}


	return this->hasColidedWithLeftTriangle(plane) || this->hasColidedWithRightTriangle(plane);
}

bool Triangle::hasColidedWithLeftTriangle(Airplane plane){
	if(plane.getXPosition() - plane.getWidth() < this->getRightTriangleX(plane)){
		return true;
	}
	return false;
}

bool Triangle::isColidingInY(Airplane plane){
	if(this->position < -this->height){
		return false;
	}

	return plane.getSuperiorY() > this->position;
}

int Triangle::getRightTriangleX(Airplane plane){

	if(this->position < 0){
		return -this->windowWidth/2+(this->base + this->baseBlockWidth);
	}

	return -this->windowWidth/2+(this->base*(this->height - this->position )/this->height + this->baseBlockWidth);
}

bool Triangle::hasColidedWithRightTriangle(Airplane plane){
	if(plane.getXPosition() + plane.getWidth() > this->getLeftTriangleX(plane)){
		return true;
	}
	return false;
}

int Triangle::getLeftTriangleX(Airplane plane){

	if(this->position < 0){
		return +this->windowWidth/2 - (this->base + this->baseBlockWidth);
	}

	return this->windowWidth/2-(((this->base*(this->height - this->position )/this->height) + this->baseBlockWidth));
}