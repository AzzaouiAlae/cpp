#include "Point.hpp"

static float triangleArea(Point A, Point B, Point C)
{
	return fabs((A.X() * (B.Y() - C.Y()) +
				 B.X() * (C.Y() - A.Y()) +
				 C.X() * (A.Y() - B.Y())) /
				2.0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float A = triangleArea(a, b, c);
	float A1 = triangleArea(point, b, c),
	A2 = triangleArea(a, point, c),
	A3 = triangleArea(a, b, point);

	return fabs(A - (A1 + A2 + A3)) <= 0.001f &&
			A1 > 0.001f && A2 > 0.001f && A3 > 0.001f;
}
