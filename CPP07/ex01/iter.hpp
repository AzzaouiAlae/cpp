#pragma once

#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl
#define temp template<typename Type1, typename Type2> 

temp void iter(Type1 arr[], const size_t len, void (*f)(Type2))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}