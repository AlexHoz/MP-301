#include "stdafx.h"
#include "glut.h"
#include <iostream>
using namespace std;

void myInit()
{
	glClearColor(0.8, 0.5, 0.3, 0);
	glColor3f(0, 0, 0);
	glPointSize(4);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
	glColor3f(1, 0.8, 0);
	glBegin(GL_POINTS);
	{
		glVertex2f(26, 267);
	}
	glEnd();
	glPointSize(65);
	glColor3f(1, 0.3, 0.8);
	glBegin(GL_POINTS);
	{
		glVertex2f(220, 600);
	}
	glEnd();
	glPointSize(20);
	glColor3f(0.3, 1, 1);
	glBegin(GL_POINTS);
	{
		glVertex2f(600, 15);
	}
	glEnd();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
