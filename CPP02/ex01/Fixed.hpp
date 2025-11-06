#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <math.h>

#define string std::string
#define cout std::cout
#define endl std::endl

class Fixed {
	int value;
	static const int fBits;
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif