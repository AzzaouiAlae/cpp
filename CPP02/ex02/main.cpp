#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << b << endl;
	
	cout << Fixed::max( a, b ) << endl;
	return 0;
}
