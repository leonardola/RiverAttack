#include "Blocks.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <iostream>

Blocks::Blocks(int windowHeight, int windowWidth){

	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;

	this->objectType = this->getRandomBlock();
	
}

/**
* desenha o bloco escolhido no inicio apartir da posição inicial
**/
int Blocks::drawBlock(int initialPosition){

	int finalPosition = 0;

	switch(this->objectType){

		case 0:
			finalPosition = this->drawBase(initialPosition);
			break;
		case 1:
			finalPosition = this->drawTriangle(initialPosition);
			break;
	}

	return finalPosition;

}

/**
* gera um numero randomico para usar um bloco diferente em cada instancia
**/
int Blocks::getRandomBlock(){

	//25 + ( std::rand() % ( 63 - 25 + 1 ) ) de 25 a 63

	int type = 0 + ( std::rand() % ( 2 - 0 ) ); //randomico de 0 a 2

	return type;

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

	/*glBegin(GL_POLYGON);
		glColor3f(1.0 , 1.0, 0.0); //cor
		glVertex2f(-this->windowWidth/2, 200 + initial);
		glVertex2f(-this->windowWidth/2 + 200, 200 + initial);
		glVertex2f(-this->windowWidth/2 + 100, 100 + initial);
		glVertex2f(-this->windowWidth/2 + 100, initial);
		glVertex2f(-this->windowWidth/2, initial);
	glEnd();*/

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