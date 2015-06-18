#include "Score.h"


Score::Score(void)
{
}

void Score::draw(){

}

Score::Score(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->score = 0;
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


