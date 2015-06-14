#include "Blocks.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <random>

Blocks::Blocks(void){

}

Blocks::Blocks(int windowHeight, int windowWidth){

	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;

	this->objectType = this->getRandomBlock();
	this->blockHeight = 200;
	
}

/**
* desenha o bloco escolhido no inicio apartir da posição inicial
**/
int Blocks::drawBlock(int initialPosition){

	int finalPosition = 0;

	if(this->objectType < 50){
		finalPosition = this->drawBase(initialPosition);
	}else{
		finalPosition = this->drawTriangle(initialPosition);
	}

	return finalPosition;

}

/**
* gera um numero randomico para usar um bloco diferente em cada instancia
**/
int Blocks::getRandomBlock(){

	 return rand()%100;

	/*std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0,50); // guaranteed unbiased

	auto random_integer = uni(rng);

	return random_integer;*/
}


Blocks::~Blocks(void)
{
}

/**
* desenha o bloco base 
**/
int Blocks::drawBase(int initial){

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

/**
* desenha um bloco triangulo
*/
int Blocks::drawTriangle(int initial){

	//esquerdo
	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(-this->windowWidth/2, 200 + initial);
		glVertex2f(-this->windowWidth/2 + 200, 200 + initial);
		glVertex2f(-this->windowWidth/2 + 100, initial);
		glVertex2f(-this->windowWidth/2, initial);
		//glVertex2f(-this->windowWidth/2 - 100, 100 + initial);
	glEnd();


	//direito
	glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(this->windowWidth/2 - 200, 200 + initial);
		glVertex2f(this->windowWidth/2, 200 + initial);
		glVertex2f(this->windowWidth/2, initial);
		glVertex2f(this->windowWidth/2 - 100, initial);
		glVertex2f(this->windowWidth/2 - 100, 100 + initial);
	glEnd();

	return initial + 200;

}

int Blocks::getBlockHeight(){
	return this->blockHeight;
}

bool Blocks::hasColided(Airplane plane){

	if(this->objectType < 50){
		return this->hasColidedWithBase(plane);
	}else{
		return this->hasColidedWithTriangle(plane);
	}

}

bool Blocks::hasColidedWithBase(Airplane plane){
	
	plane.getYPosition();

	return this->hasColidedWithLeftBase(plane) || this->hasColidedWithRightBase(plane);

}

bool Blocks::hasColidedWithLeftBase(Airplane plane){
	return plane.getXPosition() - plane.getWidth() < -this->windowWidth/2 + 100;
}

bool Blocks::hasColidedWithRightBase(Airplane plane){
	return plane.getXPosition() + plane.getWidth() > this->windowWidth/2 - 100;
}

bool Blocks::hasColidedWithTriangle(Airplane plane){
	return false;
}


