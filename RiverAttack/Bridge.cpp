#include "Bridge.h"


Bridge::Bridge(void)
{
}

Bridge::~Bridge(void)
{
}

Bridge::Bridge(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->height = 100;
	this->width = 100000;
	this->destroyed = false;
	this->yPosition = windowHeight + this->height;
	this->xPosition = 0;
	this->position = 0;
}


int Bridge::draw(int position){

	this->yPosition -= 3;

	if(this->destroyed){
		return position;
	}

	glBegin(GL_POLYGON);
		glColor3f(0.3 , 0.3, 0.3); //cor
		glVertex2f(-this->windowWidth/2, this->yPosition + this->height);
		glVertex2f(this->windowWidth/2, this->yPosition + this->height);
		glVertex2f(this->windowWidth, this->yPosition - this->height);
		glVertex2f(-this->windowWidth, this->yPosition - this->height);
	glEnd();

	return position;

}

void Bridge::reset(){
	this->yPosition = this->windowHeight + this->height;
	this->destroyed = false;
}
