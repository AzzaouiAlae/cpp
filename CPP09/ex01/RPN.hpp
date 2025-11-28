#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <stdint.h>

#define string std::string
#define cout std::cout
#define endl std::endl


class RPN 
{
	bool isOperator(char ch);
	RPN(const RPN& obj);
	RPN& operator=(const RPN& obj);
	int firstDigit(const string& str, size_t start);
	int firstOperator(const string& str, size_t start);
	void PerformCalc(const string& input);
	bool isNumber(const string& input, size_t& start);
	void Calc(std::stack<long>& nums, char op);
	void Parse(const string& input);
	RPN();
public:
	RPN(const string& input);
	~RPN();
	class RPNException : public std::exception
	{
		const string msg;
	public:
		~RPNException() throw();
		RPNException(const string& msg);
		const char *what() const throw() ;
	};
};