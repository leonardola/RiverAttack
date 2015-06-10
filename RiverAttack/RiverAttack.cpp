#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <cmath>
#include "Blocks.h"

#define janela_altura 768
#define janela_largura 1024

Blocks blocks(janela_altura,janela_largura);

void desenhar (int initial);
void display (void);
void keyboard();
void tela(GLsizei w, GLsizei h);
void animate(int val);


int position = 0;
int animationTime = 10;



int main(int argc, char** argv){

	glutInit(&argc, argv); // suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // padrão de cores

	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(100, 100); //posicao que surge a janela
	glutCreateWindow("River Attack"); //cria a janela

	glutReshapeFunc(tela); //configura a tela
	glutDisplayFunc(display);

	glutTimerFunc(animationTime,animate,1);

	glutMainLoop();//redesenhar

	return (0);

}

void display(){

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //cor do fundo

	glClear(GL_COLOR_BUFFER_BIT); //EXECUTA A LIMPEZA

	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();

	
	//ESPECIFICAR O LOCAL AONDE O DESENHO ACONTECE: BEM NO CENTRO DA JANELA MAIS TRANSLACAO
	glTranslated(janela_largura/2, janela_altura/2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);

	glFlush();//execute o desenho

}


void tela(GLsizei w, GLsizei h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//cria a janela(esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);
}

void desenhar(int initial){

	glClear(GL_COLOR_BUFFER_BIT); //EXECUTA A LIMPEZA

	initial = blocks.drawBase(initial);
	blocks.drawTriangle(initial);

	glFlush();

}


void animate(int val){

	desenhar(position);

	position--;

	glutTimerFunc(animationTime,animate,1);

}