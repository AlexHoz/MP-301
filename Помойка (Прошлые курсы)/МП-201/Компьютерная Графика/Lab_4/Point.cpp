#include "Point.h"

// Конструкторы
Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

// Методы
double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

double Point::getSize()
{
	return 0.0;
}

void Point::draw()
{
	glBegin(GL_POINTS);
	{
		glVertex2f(this->x, this->y);
	}
	glEnd();
}

void Point::print()
{
	cout << "x: " << this->x << ", y: " << this->y << ";" << endl;
}

void Point::change(string key) {}

// Деструкторы
Point::~Point()
{
}

