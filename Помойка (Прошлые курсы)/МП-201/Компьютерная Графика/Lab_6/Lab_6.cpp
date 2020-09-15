#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "glut.h"
#include <cmath>
#include <time.h>
#include <stddef.h>

using namespace std;

//Размеры окна
int Width = 610;
int Hight = 610;

//Радиус окружности 
float Radius = 300;


float AngleS;
float AngleM;
float AngleH;

//Метод отрисовки окружности
void drawCircle(float x, float y, float radius, float angleB, float angleE)
{
	glBegin(GL_LINE_STRIP);
	for (float alpha = angleB; alpha <= angleE; alpha += M_PI / 1000)
		glVertex2f(radius * cos(alpha) + x, radius * sin(alpha) + y);
	glEnd();
}
//метод отрисовки  часов
void drawClock(float x, float y, float radius)
{
	glColor3f(0, 0, 0);
	//Окружность
	drawCircle(x, y, radius, 0, 2*M_PI);
	//Горизонтальные линии
	glBegin(GL_LINES);
	for (float i = 0; i < 2 * M_PI; i += M_PI / 6)
	{
		glColor3f(1, 0, 0);
		glVertex2f((radius) * cos(i) + x, (radius) * sin(i) + y), glVertex2f((radius - 40) * cos(i) + x, (radius - 40) * sin(i) + y);
		glColor3f(0, 0, 0);
		for (float j = i + M_PI / 30; j < i + M_PI / 6 - M_PI / 36; j += M_PI / 30)
		{
			glVertex2f((radius)*cos(j) + x, (radius)*sin(j) + y), glVertex2f((radius - 20) * cos(j) + x, (radius - 20) * sin(j) + y);
		}
	}
	glEnd();
}

//метод отрисовки стрелки
void drawArrow(float x, float y, float radius, float angle)
{
	glBegin(GL_LINES);
	glVertex2f((radius - 10) * cos(angle) + x, (radius - 10) * sin(angle) + y), glVertex2f(x, y);
	glEnd();
}

void myInit()
{
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Width, 0, Hight);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawClock(Width / 2, Hight / 2, Radius);
	glColor3f(1, 0, 0);
	drawArrow(Width / 2, Hight / 2, Radius - 20, AngleS);
	glColor3f(0, 1, 0);
	drawArrow(Width / 2, Hight / 2, Radius - 40, AngleM);
	glColor3f(0, 0, 1);
	drawArrow(Width / 2, Hight / 2, Radius - 60, AngleH);
	glFlush();
}
void TimerFunction(int value)
{
	time_t now = time(0);
	tm* t_m = localtime(&now);
	AngleS = -t_m->tm_sec * M_PI / 30 + M_PI / 2;
	AngleM = -t_m->tm_min * M_PI / 30 + M_PI / 2;
	AngleH = -t_m->tm_hour * M_PI / 6 + M_PI / 2;
	glutPostRedisplay();
	glutTimerFunc(1000, TimerFunction, 1);
}
int main(int argc, char** argv)
{
	time_t now = time(0);
	tm* t_m = localtime(&now);
	AngleS = -t_m->tm_sec * M_PI / 30 + M_PI / 2;
	AngleM = -t_m->tm_min * M_PI / 30 + M_PI / 2;
	AngleH = -t_m->tm_hour * M_PI / 6 + M_PI / 2;
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	//устанавливаем режим дисплея
	glutInitWindowSize(Width, Hight);
	//устанавливаем размер окна
	glutInitWindowPosition(100, 150);
	//устанавливаем положение окна на экране
	glutCreateWindow("Лабораторная работа №6");
	//открываем окно на экране
	glutDisplayFunc(myDisplay);
	glutTimerFunc(1000, TimerFunction, 1);
	myInit();
	glutMainLoop();
	//входим в бесконечный цикл
}