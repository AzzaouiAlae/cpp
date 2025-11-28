#pragma once

#include <iostream>
#include <sstream>
#include "Int.hpp"
#include "Double.hpp"
#include "Float.hpp"

#define string std::string
#define cout std::cout
#define endl std::endl

class Float;
class Int;
class Double;

class Char
{
	bool isImpossible;
	bool isNonDisplayable;
	char c;
public:
	Char();
	~Char();
	Char(const Char& ch);
	Char (const string& s);
	Char (const Int& num);
	Char (const Float& num);
	Char (const Double& num);
	Char& operator=(const Char& ch);
	bool isValidNumber(const string& s, float num, const string& end);
	string toString() const;
	char Character() const;
	bool IsImpossible() const;
};

std::ostream& operator<<(std::ostream& os, Char& ch) ;