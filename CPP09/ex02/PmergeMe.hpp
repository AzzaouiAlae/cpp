#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <stdint.h>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <deque>
#include <sstream>

#include <fstream>
#include <unistd.h>

#define Integer PmergeMe::Int

class PmergeMe
{
	size_t t_sequence(size_t k);

public:
	class Int
	{
		unsigned char c;
		int idxs[35];

	public:
		int value;
		static int Count;

		void saveIndex(int idx);
		int GetIndex();

		bool operator<(const Int &other) const;
		bool operator!=(const Int &other) const;
		Int &operator=(const Int &other);

		Int(int val);
		Int(const Int &obj);
		~Int();
		Int (const std::string& s) ;
		bool isValidNumber(const std::string& s, long num, const std::string& end);
	};
	void MergeInsert(std::vector<Integer > &nums);
	void MergeInsert(std::deque<Integer > &nums);
	void MISort(char *argV[]);
	class PmergeMeException : public std::exception
	{
		const std::string msg;
	public:
		~PmergeMeException() throw();
		PmergeMeException(const std::string& msg);
		const char *what() const throw() ;
	};
private:
	void MakePairs(std::vector<Integer> &nums, std::vector<Integer>& a, std::vector<Integer> &b);
	void restB(std::vector<Integer>& a, std::vector<Integer>& b, std::vector<Integer>& restorB);

	void MakePairs(std::deque<Integer>& nums, std::deque<Integer>& a, std::deque<Integer> &b);
	void restB(std::deque<Integer>& a, std::deque<Integer >& b, std::deque<Integer>& restorB);

	void Parse(char *argV[]);
	std::vector<Integer> vNums;
	std::deque<Integer> dNums;
	void MISortVector();
	void MISortDeque();
};

std::ostream &operator<<(std::ostream &o, const Integer &i);

