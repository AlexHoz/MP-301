#include <iostream>
#include "glut.h"
#include "Point.h"
using namespace std;

int n = 3;
Point* T = new Point[n];


//Метод для отрисовки всех точек
void drawObject()
{
	int r = rand() % n; //Выбираем рандомную точку
	for (int i = 0; i < n; i++)
	{
		T[i].drawPoint();
	}
	Point p1, p;
	r = rand() % n;//Выбираем рандомную точку p1
	p1.setX(T[r].getX()), p1.setY(T[r].getY());
	r = rand() % n;//Выбираем рандомную точку p
	p.setX((T[r].getX() + p1.getX()) / 2.);
	p.setY((T[r].getY() + p1.getY()) / 2.);
	p.drawPoint();

	for (int i = 0; i < 500000; ++i)
	{
		r = rand() % n;
		p.setX((T[r].getX() + p.getX()) / 2.);
		p.setY((T[r].getY() + p.getY()) / 2.);
		p.drawPoint();
	}
}

void myInit()
{
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawObject();
	glFlush();
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0, x, y; i < n; i++) {
		cout << "Введите координaты точки "<< i + 1 << ": ";
		cin >> x >> y;
		T[i].setX(x), T[i].setY(y);
	}
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	//устанавливаем режим дисплея
	glutInitWindowSize(800, 800);
	//устанавливаем размер окна
	glutInitWindowPosition(100, 150);
	//устанавливаем положение окна на экране
	glutCreateWindow("Лабораторная работа №1");
	//открываем окно на экране
	glutDisplayFunc(myDisplay);
	//glutMotionFunc( myMovedMouse );
	//регистрируем функции обратного вызова
	myInit();
	glutMainLoop();
	//входим в бесконечный цикл
}