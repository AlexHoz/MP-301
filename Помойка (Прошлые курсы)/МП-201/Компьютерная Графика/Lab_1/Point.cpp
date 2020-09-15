#include "glut.h"
#include "Point.h"
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::setX(float x) { this->x = x; }

void Point::setY(float y) { this->y = y; }

float Point::getX() const { return this->x; }

float Point::getY() const { return this->y; }

void Point::drawPoint() const
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}