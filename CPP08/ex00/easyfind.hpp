#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define string std::string
#define cout std::cout
#define endl std::endl
#define temp template<typename T> 
#define vector std::vector

temp int easyfind(T cont, int toFind)
{
	typename T::iterator res = std::find(cont.begin(), cont.end(), toFind);
	if (res != cont.end())
		return *res;
	throw std::exception();
}
