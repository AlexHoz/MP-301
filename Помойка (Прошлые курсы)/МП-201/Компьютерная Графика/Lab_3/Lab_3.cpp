#include <iostream>
#include "glut.h"
#include "Vector.h"
#define M_PI 3.14159265358979323846
using namespace std;


int Width = 800;
int Hight = 800;

float speadM = 10;
float speadR = 2;

Vector vec = Vector(200, 200, 400, 200);


string Key_Q = "QqЙй";
string Key_E = "EeУу";

string Key_W = "WwЦц";
string Key_S = "SsЫы";
string Key_A = "AaФф";
string Key_D = "DdВв";

string Key_R = "RrКк";
string Key_T = "TtЕе";

bool FindKey(char pressKey, string keyArray)
{
	for (char key : keyArray)
		if (key == pressKey)
			return true;
	return false;
}
void myKeyboard(unsigned char key, int x, int y)
{
	if (FindKey(key, Key_W))
	{
		vec.setAY(vec.getAY() + speadM);
		vec.setBY(vec.getBY() + speadM);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_S))
	{
		vec.setAY(vec.getAY() - speadM);
		vec.setBY(vec.getBY() - speadM);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_A))
	{
		vec.setAX(vec.getAX() - speadM );
		vec.setBX(vec.getBX() - speadM);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_D))
	{
		vec.setAX(vec.getAX() + speadM);
		vec.setBX(vec.getBX() + speadM);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_Q))
	{
		vec.setAngle(vec.getAngle() + speadR);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_E))
	{
		vec.setAngle(vec.getAngle() - speadR);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_R))
	{
		vec.setScaler(vec.getScaler() * 1.05);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_T))
	{
		vec.setScaler(vec.getScaler() * 0.95);
		glutPostRedisplay();
	}
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	vec.Draw();
	glFlush();
}

void myInit()
{
	glColor3f(1, 0, 0);
	glPointSize(5);
	glClearColor(1, 1, 1, 1); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Width, 0, Hight);
}


int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Width, Hight);
	glutCreateWindow("Лабораторная работа №3");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	myInit();
	glutMainLoop();
}