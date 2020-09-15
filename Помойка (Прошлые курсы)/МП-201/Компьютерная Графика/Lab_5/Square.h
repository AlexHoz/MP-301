#ifndef _Square
#define _Square
class Square
{
private:
	float x;
	float y;
	float size;
	float angle = 0;
public:
	Square(float x, float y, float size);
	void setX(float x);
	void setY(float y);
	void setSise(float size);
	void setAngle(float angle);

	float getX() const;
	float getY() const;
	float getSise() const;
	float getAngle() const;
	void drawVector();
	
};
#endif