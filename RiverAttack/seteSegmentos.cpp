#include "seteSegmentos.h"


seteSegmentos::seteSegmentos(void){
	this->formaSegmento.setCor(1,1,1);
}


seteSegmentos::seteSegmentos(int windowHeight, int windowWidth){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
}

void seteSegmentos::drawOneDisplay(int valor, int posX, int posY){
	if(valor != 1 && valor != 4){ // a
		formaSegmento.geraQuadrado(posX-5, posX+5, posY-2+8, posY+2+8);
	}
	if(valor != 5 && valor != 6 ){ // b
		formaSegmento.geraQuadrado(posX+5, posX+9, posY-2, posY+10);
	}
	if(valor != 2){ // c
		formaSegmento.geraQuadrado(posX+5, posX+9, posY-10, posY+2);
	}
	if(valor != 1 && valor != 4 && valor != 7){ // d
		formaSegmento.geraQuadrado(posX-5, posX+5, posY-2-8, posY+2-8);
	}
	if(valor == 0 || valor == 2 || valor == 6 || valor == 8){ // e
		formaSegmento.geraQuadrado(posX-9, posX-5, posY-10, posY+2);
	}
	if(valor >= 4 && valor <= 9 || valor == 0){ // f
		formaSegmento.geraQuadrado(posX-9, posX-5, posY-2, posY+10);
	}
	if(valor != 0 && valor != 1 && valor != 7){ // g
		formaSegmento.geraQuadrado(posX-5, posX+5, posY-2, posY+2);
	}
}
void seteSegmentos::draw(int pontuacao){
	drawOneDisplay(pontuacao%10,this->windowWidth/2 -130,50);
	int valor = pontuacao/10;
	drawOneDisplay(valor%10,this->windowWidth/2 -155,50);
	valor = valor/10;
	drawOneDisplay(valor%10,this->windowWidth/2 -180,50);
	valor = valor/10;
	drawOneDisplay(valor%10,this->windowWidth/2 -205,50);
}

