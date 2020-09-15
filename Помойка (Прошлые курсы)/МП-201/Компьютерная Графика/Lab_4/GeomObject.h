#pragma once
#include "Core.h"
class GeomObject
{
public:
	// Ìועמהû
	virtual double getSize() = 0;
	virtual void draw() = 0;
	virtual void print() = 0;
	virtual void change(string key) = 0;
	virtual ~GeomObject() {};
};