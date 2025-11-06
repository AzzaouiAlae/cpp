#include "Fixed.hpp"

const int Fixed::fBits = 8;

Fixed::Fixed()
{
	value = 0;
	cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& obj)
{
	cout << "Copy constructor called\n";
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	cout << "Copy assignment operator called\n";
	value = obj.getRawBits();
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
