#pragma once
#include "EnemyShape.h"
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
private:
	int numberOfEnemies;
	int windowHeight;
	int windowWidth;
	int lastPosition;
	EnemyShape *listOfEnemies[30];
	void generateEnemies();
	EnemyShape * generateRandomEnemy();
	bool shouldGenerate();
	int getRandomXPosition();
	int getRandomYPosition();
	bool Enemies::isEnemyOutOfScreen(EnemyShape * enemy);
};

