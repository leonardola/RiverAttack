#include "Score.h"


Score::Score(void)
{
}

Score::Score(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->score = 0;
	this->display = seteSegmentos(windowHeight,windowWidth);
}


Score::~Score(void)
{
}

void Score::addScore(){
	this->score++;
}

int Score::getScore(){
	return this->score;
}

void Score::draw(){
	glBegin(GL_POLYGON);
		glColor3f(0.2 , 0.2, 0.2); //cor
		glVertex2f(-this->windowWidth/2, 70 );
		glVertex2f(this->windowWidth/2, 70);
		glVertex2f(this->windowWidth/2, 0);
		glVertex2f(-this->windowWidth/2, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.9 , 0.5, 0.3); //cor
		glVertex2f(-this->windowWidth/2 - 100, 70 );
		glVertex2f(-this->windowWidth/2 + this->fuelAmountPercentage, 70);
		glVertex2f(-this->windowWidth/2 + this->fuelAmountPercentage, 0);
		glVertex2f(-this->windowWidth/2 - 100, 0);
	glEnd();

	display.draw(this->score);
}

void Score::setFuelAmount(int fuelAmount){
	this->fuelAmountPercentage = fuelAmount;
}

void Score::reset(){
	this->score = 0;
}
