#pragma once

#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl
#define temp template<typename T> 

temp void swap(T& arg1, T& arg2)
{
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

temp T& min(T& arg1, T& arg2)
{
	return (arg1 < arg2) ? arg1 : arg2;
}

temp T& max(T& arg1, T& arg2)
{
	return (arg1 > arg2) ? arg1 : arg2;
}
