#ifndef _Point
#define _Point
class Point
{
private:
	float x;
	float y;
public:
	Point(float x = 0, float y = 0);
	void setX(float x);
	void setY(float y);
	float getX() const;
	float getY() const;
	void drawPoint() const;
};
#endif