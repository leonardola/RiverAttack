#pragma once
#include <GL/glut.h>
#include "formas.h"

class seteSegmentos
{
private:
	formas formaSegmento;
	int windowHeight;
	int windowWidth;
public:		
	seteSegmentos(void);
	seteSegmentos(int windowHeight, int windowWidth);
	void drawOneDisplay(int valor, int posX, int posY);
	void draw(int pontuacao);
};