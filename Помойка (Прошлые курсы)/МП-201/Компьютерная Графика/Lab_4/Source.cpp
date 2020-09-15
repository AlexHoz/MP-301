#include "Point.h"
#include "Vector2.h"

GeomObject* MyPoint = new Point(300, 300);
GeomObject* MyVector = new Vector2(200, 200, 400, 400);

// Клавиши поворота
string Key_Q = "QqЙй";
string Key_E = "EeУу";
// Клавиши перемещения
string Key_W = "WwЦц";
string Key_S = "SsЫы";
string Key_A = "AaФф";
string Key_D = "DdВв";
// Клавиши изменения размера
string Key_R = "RrКк";
string Key_T = "TtЕе";

void myInit()
{
	glColor3f(0, 0, 0);
	glClearColor(1, 1, 1, 0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
}

bool FindKey(char pressKey, string keyArray)
{
	for (char key : keyArray)
		if (key == pressKey)
			return true;
	return false;
}

void VectorControl(unsigned char key, int x, int y)
{
	if (FindKey(key, Key_W))
	{
		MyVector->change("W");
	}
	else if (FindKey(key, Key_S))
	{
		MyVector->change("S");
	}
	else if (FindKey(key, Key_A))
	{
		MyVector->change("A");
	}
	else if (FindKey(key, Key_D))
	{
		MyVector->change("D");
	}
	else if (FindKey(key, Key_Q))
	{
		MyVector->change("Q");
	}
	else if (FindKey(key, Key_E))
	{
		MyVector->change("E");
	}
	else if (FindKey(key, Key_R))
	{
		MyVector->change("R");
	}
	else if (FindKey(key, Key_T))
	{
		MyVector->change("T");
	}
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3);
	MyPoint->draw();
	glPointSize(1);
	MyVector->draw();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Лабораторная работа №4 | Михалев Андрей | МП-201");
	glutDisplayFunc(myDisplay);
	myInit();
	glutKeyboardFunc(VectorControl);
	glutMainLoop();
	return 0;
}