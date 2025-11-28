#pragma once

#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl
#define temp template<typename T> 

temp class Array 
{
	T *arr;
	unsigned int n;
public:

	Array() {
		n = 0;
		arr = NULL;
	};

	Array(unsigned int n) {
		arr = new T[n];
		for(size_t i = 0; i < n; i++)
			arr[i] = 0;
		this->n = n;
	}

	Array(const Array& obj)
	{
		arr = NULL;
		*this = obj;
	}

	Array &operator=(const Array& obj) {
		if (arr)
			delete[] arr;
		arr = new T[obj.n];
		for(size_t i = 0; i < obj.n; i++)
			arr[i] = obj.arr[i];
		this->n = obj.n;
		return *this;
	}

	T& operator[](const size_t index)
	{
		if (index >= n)
			throw std::exception();
		return arr[index];
	}

	size_t size() const
	{
		return n;
	}

	~Array()
	{
		if (arr)
			delete[] arr;
	}
};