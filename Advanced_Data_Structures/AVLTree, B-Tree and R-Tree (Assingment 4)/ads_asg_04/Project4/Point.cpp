
#include "Point.h"

Point::Point(){
	
}
Point::~Point(){

}

int Point::getX()
{
	return this->X;
}
int Point::getY()
{
	return this->Y;
}
void Point::setX(int value)
{
	this->X = value;
}
void Point::setY(int value)
{
	this->Y = value;
}