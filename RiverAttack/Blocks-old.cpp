#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>

class Blocks-ols{

	private:
		int windowHeight;
		int windowWidth;

	Blocks-old(int windowHeight, int windowWidth){

		this->windowHeight = windowHeight;
		this->windowWidth = windowWidth;

	}

	int drawBase(int initial){

		glBegin(GL_POLYGON);
			glColor3f(1.0 , 1.0, 0.0); //cor
			glVertex2f(-this->windowWidth/2,200 + initial);
			glVertex2f(-this->windowWidth/2 + 100, 200 + initial);
			glVertex2f(-this->windowWidth/2 + 100, initial);
			glVertex2f(-this->windowWidth/2, initial);
		glEnd();

	}

}

