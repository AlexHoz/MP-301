#ifndef _Vector
#define _Vector

class Vector
{
private:
	float aX;
	float aY;
	float bX;
	float bY;
	float angle = 0;
	float _angle = 0;
	float scaler = 1;

public: 
	Vector(float aX, float aY, float bX, float bY);
	void setAX(float x);
	void setAY(float y);
	void setBX(float x);
	void setBY(float y);
	void setAngle(float angle);
	void setScaler(float scaler);

	float getAX() const;
	float getAY() const;
	float getBX() const;
	float getBY() const;
	float getAngle() const;
	float getScaler() const;
	void Draw();
			
};
#endif

