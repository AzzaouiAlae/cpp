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

class Span 
{
	vector<int> nums;
	unsigned int capacity;
	Span();
public:
	~Span();
	Span(const Span& obj);
	Span(unsigned int size);
	Span& operator=(const Span& obj);
	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	int& operator[](size_t idx);
	temp void addRange(T type)
	{
		for (typename T::iterator i = type.begin(); i < type.end(); i++)
			addNumber(*i);
	}
	temp void addRange(T begin,T end)
	{
		for (; begin < end; begin++)
			addNumber(*begin);
	}
	temp void forEach(void (*func)(T))
	{
		for(size_t i = 0; i < nums.size(); i++)
			func(nums[i]);
	}
	void addRange(int arr[], size_t len);
	size_t size();
};