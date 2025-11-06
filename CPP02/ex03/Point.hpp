#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& obj);
	Point &operator=(const Point& obj);
	~Point();
	float X();
	float Y();
};

#endif