#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
#define string std::string
#define cout std::cout
#define endl std::endl
#define temp template<typename T, typename Container = std::deque<T> > 

temp class MutantStack: public std::stack<T, Container>
{
	
public:
	MutantStack() : std::stack<T, Container>() {}

	~MutantStack() {}
	
	class iterator 
	{
		T* current;
	public:
		iterator(T* p): current(p) {}
		
		T& operator*() const {
			return *current;
		}

		iterator operator-(size_t n) {
			iterator tmp = *this;
			tmp.current += n;
			return tmp;
		}

		iterator operator+(size_t n) {
			iterator tmp = *this;
			tmp.current -= n;
			return tmp;
		}

		iterator operator++() {
			current--;
			return *this;
		}

		iterator operator++(int) {
			iterator tmp = *this;
			current--;
			return tmp;
		}

		iterator operator--() {
			current++;
			return *this;
		}

		iterator operator--(int) {
			iterator tmp = *this;
			current++;
			return tmp;
		}

		bool operator==(const iterator& obj) const {
			return current == obj.current;
		}

		bool operator!=(const iterator& obj) const {
			return current != obj.current;
		}

		bool operator<(const iterator& obj) const {
			return current > obj.current;
		}

		bool operator>(const iterator& obj) const {
			return current < obj.current;
		}

		bool operator<=(const iterator& obj) const {
			return current >= obj.current;
		}

		bool operator>=(const iterator& obj) const {
			return current <= obj.current;
		}
	};
	
	iterator begin() {
		return iterator(&*std::stack<T, Container>::c.end() - 1);
	}
	
	iterator end() {
		return iterator(&*std::stack<T, Container>::c.begin() - 1);
	}
};
