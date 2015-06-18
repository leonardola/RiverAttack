#include "InvertedTriangle.h"


InvertedTriangle::InvertedTriangle(void)
{
}

InvertedTriangle::InvertedTriangle(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->height = 200;
	this->width = 100;
	this->baseWidth = 100;
}
InvertedTriangle::~InvertedTriangle(void)
{
}

int InvertedTriangle::draw(int position){

	this->position = position;

	//esquerdo
	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(-this->windowWidth/2, this->height + position);
		glVertex2f(-this->windowWidth/2 + this->baseWidth, this->height + position);
		glVertex2f(-this->windowWidth/2 + this->width + this->baseWidth, position);
		glVertex2f(-this->windowWidth/2, position);
		//glVertex2f(-this->windowWidth/2 - 100, 100 + initial);
	glEnd();

	//esquerdo
	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(this->windowWidth/2, this->height + position);
		glVertex2f(this->windowWidth/2 - this->baseWidth, this->height + position);
		glVertex2f(this->windowWidth/2 - this->width - this->baseWidth, position);
		glVertex2f(this->windowWidth/2, position);
		//glVertex2f(-this->windowWidth/2 - 100, 100 + initial);
	glEnd();


	return position + 200;
}


bool InvertedTriangle::hasColided(Airplane plane){

	if(!this->isColidingInY(plane)){
		return false;
	}

	
	return  this->hasColidedWithLeftTriangle(plane) || this->hasColidedWithRightTriangle(plane);

}

bool InvertedTriangle::isColidingInY(Airplane plane){
	return plane.getSuperiorY() > this->position && plane.getInferiorY() < this->position + this->height;
}


bool InvertedTriangle::hasColidedWithLeftTriangle(Airplane plane){
	if(this->position > plane.getInferiorY()){
		return (plane.getXPosition() - plane.getWidth()) < -this->windowWidth/2 + this->width + this->baseWidth;
	}

	int planeLeft = plane.getXPosition() - plane.getWidth();

	if(planeLeft < -this->windowWidth/2 + this->getRelativeWidth(plane)){
		return true;
	}

	return false;
}

int InvertedTriangle::getRelativeWidth(Airplane plane){
	return (this->getRelativeHeight(plane) * this->width/this->height) + this->baseWidth;
}

int InvertedTriangle::getRelativeHeight(Airplane plane){
	return -(plane.getInferiorY() - this->position) + this->height;
}


bool InvertedTriangle::hasColidedWithRightTriangle(Airplane plane){
	if(this->position > plane.getInferiorY()){
		return (plane.getXPosition() + plane.getWidth()) > this->windowWidth/2 - this->width- this->baseWidth;
	}

	int relativeHeight = this->getRelativeWidth(plane) + this->width;
	int planeLeft = plane.getXPosition() - plane.getWidth();

	if(planeLeft > this->windowWidth/2 - relativeHeight){
		return true;
	}

	return false;
}