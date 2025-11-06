#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void printResult(bool res)
{
	cout << "Result: " << (res ? "Inside ✅" : "Outside ❌") << "\n\n";
}

int main()
{
	bool res;

	res = bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, 15));
	cout << "Case 1\nPoint(0, 0), Point(20, 0), Point(10, 30), Point(10, 15)\n";
	printResult(res);

	res = bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(0, 0));
	cout << "Case 2 (on vertex)\n";
	printResult(res);

	res = bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, 0));
	cout << "Case 3 (on edge)\n";
	printResult(res);

	res = bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, -5));
	cout << "Case 4 (outside below)\n";
	printResult(res);

	res = bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(30, 15));
	cout << "Case 5 (outside right)\n";
	printResult(res);

	res = bsp(Point(0, 0), Point(10, 1), Point(20, 0), Point(10, 5));
	cout << "Case 6 (flat triangle)\n";
	printResult(res);

	res = bsp(Point(0, 0), Point(6, 0), Point(3, 6), Point(3, 2));
	cout << "Case 7 (centroid)\n";
	printResult(res);

	res = bsp(Point(-100, -50), Point(200, 0), Point(0, 300), Point(50, 50));
	cout << "Case 8 (large triangle)\n";
	printResult(res);
	return 0;
}
