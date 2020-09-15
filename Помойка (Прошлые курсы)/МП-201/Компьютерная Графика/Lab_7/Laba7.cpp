#include <iostream>
#include <fstream> 
#include <vector> 
#include "glut.h"
#include "Matrix.h"
using namespace std;

Matrix matr;

void readImageFromBMPFile()
{

	int size = 0, pixels_adress = 0, width = 0, height = 0;
	short int bits_per_pixel = 0;

	ifstream file("lena1_1.bmp", ios::in | ios::binary);

	// Переходим на 2 байт
	file.seekg(2, ios::beg);

	// Считываем размер файла
	file.read((char*)&size, sizeof(int));

	// Переходим на 10 байт
	file.seekg(10, ios::beg);

	// Считываем адрес начала массива пикселей
	file.read((char*)&pixels_adress, sizeof(int));


	file.seekg(18, ios::beg);

	// Считываем ширину и высоту изображения (в пикселях)
	file.read((char*)&width, sizeof(int));

	file.read((char*)&height, sizeof(int));


	file.seekg(28, ios::beg);

	// считываем кол-во битов на пиксель
	file.read((char*)&bits_per_pixel, sizeof(short int));

	file.seekg(pixels_adress, ios::beg);

	// Выводим всю информацию на экран
	cout << "Size: " << size << endl;
	cout << "pixels_adress: " << pixels_adress << endl;
	cout << "bits per pixel: " << bits_per_pixel << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;

	matr.resize(width, height);
	if (bits_per_pixel == 24)
	{
		unsigned int r = 0;
		unsigned int g = 0;
		unsigned int b = 0;
		unsigned int bgr = 0;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				file.read((char*)&b, 1);
				file.read((char*)&g, 1);
				file.read((char*)&r, 1);

				matr.setr(x, y, (int)r);
				matr.setg(x, y, (int)g);
				matr.setb(x, y, (int)b);
			}
		}
	}
}

string Key_A = "AaФф";
string Key_D = "DdВв";

bool FindKey(string keyArray, char pressKey)
{
	for (char key : keyArray)
		if (key == pressKey)
			return true;
	return false;
}

void processNormalKeys(unsigned char key, int  x, int  y)
{
	if (FindKey(Key_A, key)) {
		matr.show_border();
	}
	if (FindKey(Key_D, key)) {
		matr.show_bin();
	}
}

void myInit()
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);

}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); /*Функция очищения экрана*/
	readImageFromBMPFile();
	matr.matrix_bin_transform();
	matr.show_bin();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//устанавливаем режим дисплея
	glutInitWindowSize(640, 480);
	//устанавливаем размер окна
	glutInitWindowPosition(100, 150);
	//устанавливаем положение окна на экране
	glutCreateWindow("Лабораторная работа №7");
	//открываем окно на экране
	glutDisplayFunc(myDisplay);
	//регистрируем функции обратного вызова
	myInit();
	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	//входим в бесконечный цикл
}