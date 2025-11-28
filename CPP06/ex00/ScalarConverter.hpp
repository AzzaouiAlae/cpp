#pragma once
#include <iostream>
#include <sstream>
#include "Char.hpp"
#include "Int.hpp"
#include "Double.hpp"
#include "Float.hpp"

#define string std::string
#define cout std::cout
#define endl std::endl

typedef enum eType {
	eInt,
	eChar,
	eFloat,
	eDouble,
	eNone
} eType;

class ScalarConverter 
{
	static void toChar(const string& s);
	static void toInt(const string& s);
	static void toFloat(const string& s);
	static void toDouble(const string& s);
	static void Print(Char &c, Int& i, Float& f, Double& d);
	static eType CheckType(const string& s);
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter();
public:
	static void convert(const string& s);
};


