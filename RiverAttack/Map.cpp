#include "Map.h"

Map::Map(void){

}
Map::Map(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->sizeOfMap = 100;
	this->traveledDistance = 0;
	this->firstElement = 0;

	for(int i = 0; i < this->sizeOfMap; i++){
		this->listOfBlocks[i] = Blocks(windowHeight, windowWidth);
	}
}

Map::~Map(void){

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

	//this->updateMap();
}

bool Map::isFirstElement(int initialPosition){
	return initialPosition <= 0;
}

void Map::updateMap(){
	if(firstObjectIsOutOfScreen()){
		removeFirstObject();
	}
}


bool Map::firstObjectIsOutOfScreen(){
	if(this->initialPoint + this->listOfBlocks[0].getBlockHeight() < -this->windowHeight/2){
		this->traveledDistance += this->listOfBlocks[0].getBlockHeight();
		return true;
	}
	return false;
}

void Map::removeFirstObject(){

	this->arrayShift();
	
	//this->listOfBlocks[this->sizeOfMap-1] = Blocks(this->windowHeight,this->windowWidth);

}

void Map::arrayShift(){
	for(int i = 0; i < this->sizeOfMap-1; i++){
		this->listOfBlocks[i-1] = this->listOfBlocks[i];
	}
}

Blocks Map::getFirstBlock(){
	return this->listOfBlocks[this->firstElement];
}

Blocks Map::getSecondBlock(){
	return this->listOfBlocks[this->firstElement + 1];
}