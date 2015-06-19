#include "Base.h"


Base::Base(void){
}

Base::Base(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
}

Base::~Base(void){

}


/**
* desenha o bloco base 
**/
int Base::draw(int initial){

	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(-this->windowWidth/2, 200 + initial);
		glVertex2f(-this->windowWidth/2 + 100, 200 + initial);
		glVertex2f(-this->windowWidth/2 + 100, initial);
		glVertex2f(-this->windowWidth/2, initial);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(this->windowWidth/2 - 100, 200 + initial);
		glVertex2f(this->windowWidth/2 + 100, 200 + initial);
		glVertex2f(this->windowWidth/2 + 100, initial);
		glVertex2f(this->windowWidth/2 - 100, initial);
	glEnd();

	return initial + 200;
}

bool Base::hasColided(Airplane plane){
	
	return this->hasColidedWithLeftBase(plane) || this->hasColidedWithRightBase(plane);

}

bool Base::hasColidedWithLeftBase(Airplane plane){
	return plane.getXPosition() - plane.getWidth() < -this->windowWidth/2 + 100;
}

bool Base::hasColidedWithRightBase(Airplane plane){
	return plane.getXPosition() + plane.getWidth() > this->windowWidth/2 - 100;
}
