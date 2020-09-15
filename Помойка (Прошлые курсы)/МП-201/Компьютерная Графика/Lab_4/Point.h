#pragma once
#include "GeomObject.h"
class Point : public GeomObject
{
	double x, y;

public:
	// ������������
	Point();
	Point(double x, double y);
	
	// ������
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	double getSize() override;
	void draw() override;
	void print() override;
	void change(string key) override;
	// �����������
	~Point();
};

