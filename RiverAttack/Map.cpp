#include "Map.h"

Map::Map(void){

}
Map::Map(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->sizeOfMap = 400;
	this->traveledDistance = 0;
	this->firstElement = 0;

	this->generateMap();
}

Map::~Map(void){

}

void Map::generateMap(){
	for(int i = 0; i < this->sizeOfMap; i++){
		this->listOfBlocks[i] = Blocks(this->windowHeight, this->windowWidth);
	}
}

void Map::reset(){
	this->generateMap();
	this->firstElement = 0;
}

void Map::drawMap(int initial){

	this->initialPoint = initial + this->traveledDistance;
	initial = initial + this->traveledDistance;

	for(int i = 0; i < this->sizeOfMap; i++){
		if(this->isFirstElement(initial)){
			this->firstElement = i;
		}
		initial = this->listOfBlocks[i].drawBlock(initial);
	}
}

bool Map::isFirstElement(int initialPosition){
	return initialPosition <= 0;
}

bool Map::firstObjectIsOutOfScreen(){
	if(this->initialPoint + this->listOfBlocks[0].getBlockHeight() < -this->windowHeight/2){
		this->traveledDistance += this->listOfBlocks[0].getBlockHeight();
		return true;
	}
	return false;
}

Blocks Map::getFirstBlock(){
	return this->listOfBlocks[this->firstElement];
}

Blocks Map::getSecondBlock(){
	return this->listOfBlocks[this->firstElement + 1];
}

