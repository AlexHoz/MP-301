#include <iostream>
#include "glut.h"
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

//Размеры окна
int Width = 800;
int Hight = 800;
//Угол на который повёрнута стрелка
float Angle = 0;
//Скорость поворота
const float Speed = M_PI / 180;
//Радиус окружности 
float Radius = 300;
//Кнопки для поворота стрелки
string KEY_D = "DdВв";
string KEY_A = "AaФф";
bool FindKey(string keyArray, char pressKey)
{
	for (char key : keyArray) 
		if (key == pressKey)
			return true;
	return false;
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (FindKey(KEY_D, key) && Angle > 0) {
		Angle -= Speed;
		if (Angle < 0)
			Angle = 0;
	}
	else if (FindKey(KEY_A, key) && Angle < M_PI) {
		Angle += Speed;
		if (Angle > M_PI)
			Angle = M_PI;
	}
	glutPostRedisplay();
}
//Метод отрисовки окружности
void drawCircle(float x, float y, float radius)
{
	glBegin(GL_LINE_STRIP);
	for (float alpha = 0; alpha <= M_PI; alpha += M_PI / 1000)
		glVertex2f(radius * cos(alpha) + x, radius * sin(alpha) + y);
	glEnd();
}
//метод отрисовки спидометра
void drawSpeedometer(float x, float y, float radius)
{
	glColor3f(0, 0, 0);
	//Окружность
	drawCircle(x, y, radius);
	//Горизонтальные линии
	glBegin(GL_LINES);
	for (float i = 0; i < 5; i++)
	{
		glVertex2f((radius + 25) * cos(i * M_PI/4) + x, (radius + 25) * sin(i * M_PI / 4) + y), glVertex2f((radius - 25) * cos(i * M_PI / 4) + x, (radius - 25) * sin(i * M_PI / 4) + y);
	}
	glEnd();
}

//метод отрисовки стрелки
void drawArrow(float x, float y, float radius)
{
	glColor3f(255, 0, 0);
	glBegin(GL_LINES);
	glVertex2f((radius - 10) * cos(Angle) + x, (radius - 10) * sin(Angle) + y), glVertex2f(x, y);
	glEnd();
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
	drawSpeedometer(Width / 2, Hight / 2, Radius);
	drawArrow(Width / 2, Hight / 2, Radius - 40);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	//устанавливаем режим дисплея
	glutInitWindowSize(Width, Hight);
	//устанавливаем размер окна
	glutInitWindowPosition(100, 150);
	//устанавливаем положение окна на экране
	glutCreateWindow("Лабораторная работа №2");
	//открываем окно на экране
	glutDisplayFunc(myDisplay);
	myInit();
	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	//входим в бесконечный цикл
}