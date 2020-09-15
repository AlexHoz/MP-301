#include "glut.h"
#include "Square.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Square::Square(float x, float y, float size)
{
	this->x = x;
	this->y = y;
	this->size = size;
}
void Square::setX(float x) { this->x = x; }
void Square::setY(float y) { this->y = y; }
void Square::setSise(float size) { this->size = size; }
void Square::setAngle(float angle) { this->angle = angle; }

float Square::getX() const { return x; }
float Square::getY() const { return y; }
float Square::getSise() const { return size; }
float Square::getAngle() const { return angle; }

void Square::drawVector()
{
	glPushMatrix(); 
	glTranslatef(x + size / 2, y + size / 2, 0.0);
	glRotated(angle, 0, 0, 1);
	glTranslatef(-(x + size / 2), -(y + size / 2), 0.0);

	
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2d(x, y);
	glVertex2d(x, y + size);
	glVertex2d(x + size, y +size);
	glVertex2d(x + size, y);
	glEnd();

	
	float _x = x + size / 2 - 2.5;
	float _y = y + size / 2 - 2.5;
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2d(_x, _y);
	glVertex2d(_x, _y + 5);
	glVertex2d(_x + 5, _y + 5);
	glVertex2d(_x + 5, _y);
	glEnd();
	
	/* 
	glPointSize(5);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2d(x + size / 2, y + size / 2);
	glEnd();*/

	glPopMatrix();
	glFinish();
}