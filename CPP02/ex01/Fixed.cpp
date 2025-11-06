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
	value = ((int)number << fBits);
	float f = number - (int)number;
	for(int i = 0; i < fBits; i++)
		f *= 2;
	if (f - (float)((int)f) >= 0.5f)
		f += 1;
	value += f;
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
	float v = ((int)value >> fBits);
	float f = value - ((int)v << fBits);
	for(int i = 0; i < fBits; i++)
		f /= 2;
	return v + f;
}

int Fixed::toInt() const
{
	return value >> fBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
