#pragma once
#include <GL/glut.h>
#include <math.h>

class formas{
private:
	float r, g, b;
public:
	formas(void);
	void setCor(float r, float g, float b);
	void gerarCirculo(int rx, int ry, int x1, int y1);
	void geraQuadrado(int x1, int x2, int y1, int y2);
	void geraTriangulo(int x1, int x2,int x3, int y1, int y2, int y3);
	void geraPoligono(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
	void geraBorda(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
};

