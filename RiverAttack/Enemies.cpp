#include "Enemies.h"


Enemies::Enemies(void)
{
}


Enemies::~Enemies(void)
{
}

Enemies::Enemies(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->numberOfEnemies = 30;
	this->lastPosition = this->windowHeight;
	this->generateEnemies();
}

void Enemies::generateEnemies(){
	for(int i = 0; i < this->numberOfEnemies ; i++){
		if(this->shouldGenerate()){
			this->listOfEnemies[i] = this->generateRandomEnemy(); 
		}else{
			i--;
		}
	}
}

bool Enemies::shouldGenerate(){

	int random = rand() % 100;

	if(random < 90){
		return true;
	}

	return false;

}

void Enemies::draw(int position){
	for(int i = 0; i < this->numberOfEnemies; i++){
		this->listOfEnemies[i]->draw(position);
	}
}

EnemyShape * Enemies::generateRandomEnemy(){

	int random = rand() % 100;

	if(random < 50){
		Boat *enemy = new Boat(this->windowHeight, this->windowWidth);
		enemy->setXPosition(this->getRandomXPosition());
		enemy->setYPosition(this->getRandomYPosition());
		return enemy;
	}else{
		Helicopter *enemy = new Helicopter(this->windowHeight, this->windowWidth);
		enemy->setXPosition(this->getRandomXPosition());
		enemy->setYPosition(this->getRandomYPosition());
		return enemy;
	}
}

int Enemies::getRandomXPosition(){
	int random = rand()%100;

	if(random < 33){
		return -this->windowWidth/4;
	}else if(random < 66){
		return 0;
	}else{
		return this->windowWidth/4;
	}
}

int Enemies::getRandomYPosition(){

	if(!this->shouldGenerate()){
		return this->lastPosition;
	}

	int random = rand() % 100;

	if(random < 25){
		this->lastPosition += this->windowHeight/4;
		return this->lastPosition;
	}else if(random < 50){
		this->lastPosition += this->windowHeight/2;
		return this->lastPosition;
	}else{
		this->lastPosition += this->windowHeight;
		return this->lastPosition;
	}
}

bool Enemies::bulletHasCollided(Bullet bullet){
	
	for(int i = 0 ; i < this->numberOfEnemies ; i++){
		if(this->isEnemyOutOfScreen(this->listOfEnemies[i])){
			return false;
		}
		if(this->listOfEnemies[i]->bulletHasCollided(&bullet)){
			this->listOfEnemies[i]->setDestroyed();
			return true;
		}
	}

	return false;
}

bool Enemies::isEnemyOutOfScreen(EnemyShape * enemy){
	return enemy->getBottomPosition() > this->windowHeight;
}