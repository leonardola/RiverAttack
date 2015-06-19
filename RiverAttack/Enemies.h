#pragma once
#include "BoxShape.h"
#include "Boat.h"
#include "Bullet.h"
#include "Helicopter.h"
class Enemies
{
public:
	Enemies(void);
	~Enemies(void);
	Enemies(int windowHeight, int windowWidth);
	bool bulletHasCollided(Bullet bullet);
	void draw(int position);
	bool hasColided(Airplane plane);
	bool isLastEnemy();
private:
	int numberOfEnemies;
	int windowHeight;
	int windowWidth;
	int lastPosition;
	BoxShape *listOfEnemies[30];
	void generateEnemies();
	BoxShape * generateRandomEnemy();
	bool shouldGenerate();
	int getRandomXPosition();
	int getRandomYPosition();
	bool lastEnemy;
	bool Enemies::isEnemyOutOfScreen(BoxShape * enemy);
};

