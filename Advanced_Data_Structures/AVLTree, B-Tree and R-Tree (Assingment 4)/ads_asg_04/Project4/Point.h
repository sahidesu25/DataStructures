#pragma once
#include "Interfaces04.h"

class Point : public IPoint{

public:
	Point();
	~Point();
	int getX();
	int getY();
	void setX(int value);
	void setY(int value);
private:
	int X;
	int Y;
};