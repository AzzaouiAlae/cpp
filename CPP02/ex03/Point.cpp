#include "Point.hpp"

float Point::X()
{
	return x.toFloat();
}

float Point::Y()
{
	return y.toFloat();
}

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point& obj) : x(obj.x), y(obj.y)
{
}

Point& Point::operator=(const Point& obj)
{
	*this = obj;
	return *this;
}

Point::~Point()
{
}