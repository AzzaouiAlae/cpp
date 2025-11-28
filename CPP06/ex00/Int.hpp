#pragma once

#include <iostream>
#include <sstream>
#include "Char.hpp"
#include "Double.hpp"
#include "Float.hpp"

#define string std::string
#define cout std::cout
#define endl std::endl

class Char;
class Float;
class Double;

class Int
{
	int number;
	bool isImpossible;
public:
	Int();
	~Int();
	Int(const Int& obj);
	Int (const string& s);
	Int (const Char& c);
	Int (const Float& f);
	Int (const Double& d);
	Int& operator=(const Int& obj);
	bool isValidNumber(const string& s, long num, const string& end);
	string toString() const;
	int Number() const;
	bool IsImpossible() const;
};

std::ostream& operator<<(std::ostream& os, Int& num) ;