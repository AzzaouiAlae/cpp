#include "theirs.hpp"

int h = 100;

char mylib::ft_to_uppercase(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 32;
	return ch;
}

double const geo::PI = 3.1459;

double geo::circumf(double radius)
{
	return 2* PI * radius;
}
