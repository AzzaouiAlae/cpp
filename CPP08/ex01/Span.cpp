#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int size)
{
	nums.reserve(size);
	capacity = size;
}

Span& Span::operator=(const Span& obj)
{
	nums = obj.nums;
	capacity = obj.capacity;
	return *this;
}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span::~Span()
{}

void Span::addNumber(int n) 
{
	if (nums.size() >= capacity)
		throw std::exception();
	nums.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (nums.size() < 2)
		throw std::exception();
	vector<int> ns = nums;
	std::sort(ns.begin(), ns.end());
	long shortest = labs((long)ns[0] - (long)ns[1]);
	for(size_t i = 0; i < ns.size() - 1; i++)
	{
		if (shortest > labs((long)ns[i] - (long)ns[i + 1]))
			shortest = labs((long)ns[i] - (long)ns[i + 1]);
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (nums.size() < 2)
		throw std::exception();
	vector<int> ns = nums;
	std::sort(ns.begin(), ns.end());
	return labs((long)ns[0] - (long)ns[ns.size() - 1]);
}

int& Span::operator[](size_t idx)
{
	if (idx >= nums.size())
		throw std::exception();
	return nums[idx];
}

void Span::addRange(int arr[], size_t len)
{
	for(size_t i = 0; i < len; i++)
		addNumber(arr[i]);
}

size_t Span::size()
{
	return nums.size();
}
