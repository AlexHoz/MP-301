#include <iostream>
#include "glut.h"
#include "Square.h"
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

//Размеры окна
int  Width = 800;
int  Hight = 800;


float Speed = 5;

string Key_Q = "QqЙй";

Square s(Width/2, Hight-20, 40);

bool FindKey(string keyArray, char pressKey)
{
	for (char key : keyArray)
		if (key == pressKey)
			return true;
	return false;
}


void processNormalKeys(unsigned char key, int  x, int  y)
{
	if (FindKey(Key_Q, key)) {
		s.setY(s.getY() - Speed);
		s.setAngle(s.getAngle() - Speed);
		glutPostRedisplay();
	}
}


void myInit()
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Width, 0, Hight);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	s.drawVector();
	glFlush();
}


int main(int  argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode( GLUT_double  | GLUT_RGB );
	//устанавливаем режим дисплея
	glutInitWindowSize(Width, Hight);
	//устанавливаем размер окна
	glutInitWindowPosition(100, 150);
	//устанавливаем положение окна на экране
	glutCreateWindow("Лабораторная работа №5");
	//открываем окно на экране
	glutDisplayFunc(myDisplay);
	myInit();
	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	//входим в бесконечный цикл
}