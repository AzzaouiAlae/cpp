#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl

class Fixed {
	int value;
	static const int fBits;
public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif