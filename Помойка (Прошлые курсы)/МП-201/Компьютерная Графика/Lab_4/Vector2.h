#pragma once
#include "Point.h"
class Vector2 : public GeomObject
{
	Point A;
	Point B;
	double angle = 0;
	double _angle = 0;
	double scale = 1;

public:
	// Конструкторы
	Vector2();
	Vector2(double x1, double y1, double x2, double y2);

	// Методы
	Point getA() const;
	Point getB() const;
	double getAngle() const;
	double getScale() const;
	void setA(double x, double y);
	void setB(double x, double y);
	void setAngle(double angle);
	void setScale(double scale);
	double getSize() override;
	void draw() override;
	void print() override;
	void change(string key) override;
	// Деструкторы
	~Vector2();
};