#include "Fixed.hpp"

const int Fixed::fBits = 8;

Fixed::Fixed()
{
	value = 0;
	cout << "Default constructor called\n";
}

Fixed::Fixed(const int number)
{
	cout << "Int constructor called\n";
	value = number << fBits;
}

Fixed::Fixed(const float number)
{
	cout << "Float constructor called\n";
	float n = number * (1 << Fixed::f);
	if (n - (int)n >= 0.5f)
		n += 1;
	value = n;
}

Fixed::Fixed(const Fixed& obj)
{
	cout << "Copy constructor called\n";
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	cout << "Copy assignment operator called\n";
	value = obj.value;
	return *this;
}

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called\n";
	return value;
}

void Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called\n";
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)value * pow(2, -fBits);
}

int Fixed::toInt() const
{
	return value * pow(2, -fBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
