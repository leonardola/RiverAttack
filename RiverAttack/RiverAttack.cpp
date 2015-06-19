#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <cmath>
#include "Map.h"
#include "Airplane.h"
#include "Colision.h"
#include "Boat.h"
#include "Enemies.h"
#include "Fuel.h"
#include "Bridge.h"
#include "Score.h"

int windowWidth = 1024;
int windowHeight = 768;


void desenhar (int initial);
void display (void);
void keyboard();
void tela(GLsizei w, GLsizei h);
void animate(int val);
void teclado();

Airplane airplane(windowHeight, windowWidth);
Map map(windowHeight,windowWidth);
Colision mapColision(&airplane, &map);
Fuel fuel(windowHeight,windowWidth);
Enemies enemies(windowHeight, windowWidth);
Bridge bridge(windowHeight, windowWidth);
Score score(windowHeight, windowWidth);

int position = 0;
int animationTime = 10;
int airPlaneXPosition = 0;
bool paused = false;

int main(int argc, char** argv){

	glutInit(&argc, argv); // suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // padrão de cores

	glutInitWindowSize(windowWidth, windowHeight); // tamanho da janela
	glutInitWindowPosition(100, 100); //posicao que surge a janela
	glutCreateWindow("River Attack"); //cria a janela

	glutReshapeFunc(tela); //configura a tela
	glutDisplayFunc(display);

	animate(position);

	glutMainLoop();//redesenhar

	return (0);
}

void display(){

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //cor do fundo

	glClear(GL_COLOR_BUFFER_BIT); //EXECUTA A LIMPEZA

	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();

	
	//ESPECIFICAR O LOCAL AONDE O DESENHO ACONTECE: BEM NO CENTRO
	glTranslated(windowWidth/2, 0, 0.0f);

	glViewport(0, 0, windowWidth, windowHeight);

	glFlush();//execute o desenho
}


void tela(GLsizei w, GLsizei h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//cria a janela(esq, direita, embaixo, em cima)
	gluOrtho2D(0, windowWidth, 0, windowHeight);

	glMatrixMode(GL_MODELVIEW);
}

void desenhar(int initial){

	glClear(GL_COLOR_BUFFER_BIT); //EXECUTA A LIMPEZA

	map.drawMap(initial);
	airplane.getKeyboardAction();
	airplane.drawPlane();
	airplane.useFuel();
	score.setFuelAmount(airplane.getFuelPercentage());
	score.draw();

	if(airplane.getFuelPercentage() < 40){
		fuel.reset(initial);
		fuel.draw(initial);
		if(fuel.hasColided(airplane)){
			fuel.setDestroyed();
			airplane.refuel();
		}
	}
	enemies.draw(initial);
	if(enemies.bulletHasCollided(*airplane.getBullet())){
		airplane.getBullet()->reset();
		score.addScore();
	}

	if(enemies.isLastEnemy()){
		bridge.draw(initial);
		if(bridge.bulletHasCollided(airplane.getBullet())){
			airplane.getBullet()->reset();
			enemies.reset(initial);
 			bridge.reset();
			score.reset();
		}
		if(bridge.hasColided(airplane)){
			airplane.explode();
			Sleep(500);
		}
	}

	if(mapColision.hasColided() || enemies.hasColided(airplane)){
		airplane.explode();
		score.reset();
		glFlush();
		Sleep(500);
	}else{
		glFlush();
	}
}


void animate(int val){

	if(!paused){
		desenhar(val);
		val -= 3;
	}

	teclado();

	glutTimerFunc(animationTime,animate,val);

}

void teclado(){

	if(GetAsyncKeyState(VK_ESCAPE)){//esc
		paused = !paused;
		Sleep(200);
	}
}