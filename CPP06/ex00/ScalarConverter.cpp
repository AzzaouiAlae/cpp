#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <cstring>

eType ScalarConverter::CheckType(const string& s)
{
	if (s.length() == 1 && !isdigit(s[0]))
		return eChar;
	for(int i = 0; s[i]; i++)
	{
		if (i == 0 && s[i] == '-')
			i++;
		if (!isdigit(s[i]))
			break;
		if (s[i + 1] == 0)
			return eInt;
	}
	if (s[s.length() - 1] == 'f' || s == "nan" || s == "nanf" || 
		s == "inf" || s == "-inf" || s == "+inf" || s == "inff" ||
		s == "-inff" || s == "+inff")
		return eFloat;
	for(int i = 0; s[i]; i++)
	{
		if (i == 0 && s[i] == '-')
			i++;
		if (!isdigit(s[i]) && s[i] != '.')
			break;
		if (s[i +1] == 0)
			return eDouble;
	}
	return eNone;
}

void ScalarConverter::Print(Char &c, Int& i, Float& f, Double& d)
{
	cout 
	<< "char  : " << c << '\n'
	<< "int   : " << i << '\n'
	<< "float : " << f << '\n'
	<< "double: " << d << '\n';
}

void ScalarConverter::toChar(const string& s)
{
	Char ch = static_cast<Char>(s);
	if (ch.IsImpossible())
		toInt(s);
	else
	{
		Int i = static_cast<Int>(ch);
		Float f = static_cast<Float>(ch);
		Double d = static_cast<Double>(ch);
		Print(ch, i, f, d);
	}
}

void ScalarConverter::toInt(const string& s)
{
	Int i = static_cast<Int>(s);
	if (i.IsImpossible())
		toFloat(s);
	else
	{
		Char c = static_cast<Char>(i);
		Float f = static_cast<Float>(i);
		Double d = static_cast<Double>(i);
		Print(c, i, f, d);
	}
}

void ScalarConverter::toFloat(const string& s)
{
	Float f = static_cast<Float>(s);
	if (f.IsImpossible())
		toDouble(s);
	else
	{
		Char c = static_cast<Char>(f);
		Int i = static_cast<Int>(f);
		Double d = static_cast<Double>(f);
		Print(c, i, f, d);
	}
}

void ScalarConverter::toDouble(const string& s)
{
	Double d = static_cast<Double>(s);
	Char c = static_cast<Char>(d);
	Int i = static_cast<Int>(d);
	Float f = static_cast<Float>(d);
	Print(c, i, f, d);
}

void ScalarConverter::convert(const string& s)
{
	eType type = CheckType(s);
	switch(type)
	{
		case eChar: 
			toChar(s);
			break;
		case eInt:
			toInt(s);
			break;
		case eFloat:
			toFloat(s);
			break;
		default:
			toDouble(s);
			break;
	}
}
