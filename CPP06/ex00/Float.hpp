#pragma once

#include <iostream>
#include <sstream>
#include "Char.hpp"
#include "Int.hpp"
#include "Double.hpp"

#define string std::string
#define cout std::cout
#define endl std::endl

class Char;
class Int;
class Double;

class Float
{
	float number;
	bool isImpossible;
public:
	Float();
	~Float();
	Float(const Float& obj);
	Float (const string& s);
	Float (const Int& num);
	Float (const Double& d);
	Float (const Char& c);
	Float& operator=(const Float& obj);
	bool isValidNumber(const string& s, const string& end);
	string toString() const;
	float Number() const;
	bool IsImpossible() const;
};

std::ostream& operator<<(std::ostream& os, Float& num);