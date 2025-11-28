#pragma once

#include <iostream>
#include <sstream>
#include "Char.hpp"
#include "Int.hpp"
#include "Float.hpp"

#define string std::string
#define cout std::cout
#define endl std::endl

class Char;
class Float;
class Int;

class Double
{
	double number;
	bool isImpossible;
public:
	Double();
	~Double();
	Double(const Double& obj);
	Double (const string& s);
	Double (const Int& i);
	Double (const Float& f);
	Double (const Char& c);
	Double &operator=(const Double& obj);
	bool isValidNumber(const string& s, const string& end);
	string toString() const;
	double Number() const;
	bool IsImpossible() const;
};

std::ostream& operator<<(std::ostream& os, Double& num);
