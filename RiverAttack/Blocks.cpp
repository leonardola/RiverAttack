#include "Blocks.h"
 

Blocks::Blocks(void){

}

Blocks::Blocks(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->getRandomBlock();
	printf("abc");
}

/**
* desenha o bloco escolhido no inicio apartir da posição inicial
**/
int Blocks::drawBlock(int initialPosition){
	return this->block->draw(initialPosition);
}

/**
* gera um numero randomico para usar um bloco diferente em cada instancia
**/
void Blocks::getRandomBlock(){

	int randomNumber = rand()%100;

	if(randomNumber < 33 ){
		this->block = new Base(this->windowHeight, this->windowWidth);
	}else if(randomNumber < 80){
		this->block = new Triangle(this->windowHeight, this->windowWidth);
	}else{
		this->block = new InvertedTriangle(this->windowHeight, this->windowWidth);
	}

}


Blocks::~Blocks(void)
{
}

bool Blocks::hasColided(Airplane plane){
	return this->block->hasColided(plane);
}

int Blocks::getBlockHeight(){
	return 200;
}