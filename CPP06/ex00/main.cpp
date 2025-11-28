#include "ScalarConverter.hpp"

int main(int argC, char *argV[])
{
	if (argC < 2)
		return 0;
	ScalarConverter::convert(argV[1]);

	return 0;
}
