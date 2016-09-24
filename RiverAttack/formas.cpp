#include "formas.h"

formas::formas(void){
	r = 1;
	g = 1;
	b = 1;
}

void formas::setCor(float r, float g, float b){
	this->r = r;
	this->g = g;
	this->b = b;
}

void formas::gerarCirculo(int rx, int ry, int x1, int y1){
	glColor3f(r, g, b); //cor
	GLfloat circ_pnt =360;
	GLfloat ang, raioX=rx, raioY=ry;
	glBegin(GL_POLYGON);		
		for(int i=0; i<circ_pnt; i++){
			ang = (2 * 3.14 * i)/circ_pnt;
			glVertex2f(cos(ang) * raioX + x1 , sin(ang) * raioY + y1);
		}
	glEnd();
}
void formas::geraQuadrado(int x1, int x2, int y1, int y2){
	glBegin(GL_QUADS);
		glColor3f(r, g, b); //cor		
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
		glVertex2f(x1, y1);
	glEnd();
}
void formas::geraTriangulo(int x1, int x2,int x3, int y1, int y2, int y3){
	glBegin(GL_TRIANGLES);
		glColor3f(r, g, b); //cor		
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
	glEnd();
}
void formas::geraPoligono(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){
	glBegin(GL_POLYGON);
		glColor3f(r, g, b); //cor		
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
	glEnd();
}
void formas::geraBorda(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){
	glBegin(GL_LINE_LOOP);
		glColor3f(r, g, b); //cor		
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
	glEnd();
}