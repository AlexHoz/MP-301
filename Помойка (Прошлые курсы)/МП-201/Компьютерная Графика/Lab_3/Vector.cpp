#include "glut.h"
#include "Vector.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Vector::Vector(float aX, float aY, float bX, float bY)
{
	this->aX = aX;
	this->aY = aY;
	this->bX = bX;
	this->bY = bY;
	angle = atan2(bY - aY, bX - aX);
	_angle = angle;
}
void Vector::setAX(float x) { this->aX = x; }
void Vector::setAY(float y) { this->aY = y; }
void Vector::setBX(float x) { this->bX = x; }
void Vector::setBY(float y) { this->bY = y; }
void Vector::setAngle(float angle){ this->angle = angle; }
void Vector::setScaler(float scaler){ this->scaler = scaler;}

float Vector::getAX() const { return this->aX; }
float Vector::getAY() const { return this->aY; }
float Vector::getBX() const { return this->bX; }
float Vector::getBY() const { return this->bY; }
float Vector::getAngle() const { return this->angle; }
float Vector::getScaler() const { return this->scaler; }

void Vector::Draw()
{
	glPushMatrix();
	glTranslatef(aX, aY, 0.0);
	glRotated(angle, 0, 0, 1);
	glScalef(scaler, scaler, 1.0); 
	glTranslatef(-aX, -aY, 0.0);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);

	glVertex2f(aX, aY);
	glVertex2f(bX, bY);

	glVertex2f(bX, bY),
		glVertex2f(30 * cos(_angle - 3 * M_PI / 4) + bX, 30 * sin(_angle - 3 * M_PI / 4) + bY);
	glVertex2f(bX, bY),
		glVertex2f(30 * cos(_angle + 3 * M_PI / 4) + bX, 30 * sin(_angle + 3 * M_PI / 4) + bY);
	glEnd();


	glPopMatrix();
	glFinish();
}