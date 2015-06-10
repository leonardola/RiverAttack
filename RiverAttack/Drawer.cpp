#include "Drawer.h"

Drawer::Drawer(int windowHeight, int windowWidth){

	this->windowHeight = windowHeight;
	this->startingPosition = -windowHeight/2;

	this->mapBlocks[0]->get

}

void Drawer::createBaseMap(int windowHeight, int windowWidth){

	for(int i = 0; i < 10; i++){

		this->mapBlocks[i] = new Blocks(windowHeight,windowWidth);

	}

}


Drawer::~Drawer(void){

}


void Drawer::drawMap(int inicialPosition){

	

}


