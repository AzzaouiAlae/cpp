#include "Double.hpp"
#include <cstdlib>
#include <cerrno>
#include <cstring>

Double::Double()
{
	number = 0;
	isImpossible = true;
}

Double::~Double()
{}

Double::Double(const Double& obj)
{
	number = obj.number;
	isImpossible = obj.isImpossible;
}

Double& Double::operator=(const Double& obj)
{
	number = obj.number;
	isImpossible = obj.isImpossible;
	return *this;
}

bool Double::isValidNumber(const string& s, const string& end)
{
	if (s == "")
		return false;
	if (end != "f" && end != "")
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

Double::Double (const string& s)
{
	char *end;
	double num = std::strtod(s.c_str(), &end);

	number = 0;
	isImpossible = false;

	if (!isValidNumber(s, end))
		isImpossible = true;
	else
		number = num;
}

Double::Double (const Int& i)
{
	number = 0;
	isImpossible = false;

	number = static_cast<double>(i.Number());
}

Double::Double (const Float& f)
{
	number = 0;
	isImpossible = false;

	number = static_cast<double>(f.Number());
}

Double::Double (const Char& c)
{
	number = 0;
	isImpossible = false;

	number = static_cast<double>(c.Character());
}

string Double::toString() const {
	if (isImpossible)
		return "Imposible";
	std::stringstream s;
	s << std::fixed << number;
	return s.str();
}

std::ostream& operator<<(std::ostream& os, Double& num) 
{
	os << num.toString();
	return os;
}

double Double::Number() const 
{
	return number;
}

bool Double::IsImpossible() const
{
	return isImpossible;
}