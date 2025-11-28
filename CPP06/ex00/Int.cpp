#include "Int.hpp"
#include <cstdlib>
#include <cerrno>
#include <cstring>

Int::Int()
{
	number = 0;
	isImpossible = true;
}

Int::~Int()
{}

Int::Int(const Int& obj)
{
	number = obj.number;
	isImpossible = obj.isImpossible;
}

Int& Int::operator=(const Int& obj)
{
	number = obj.number;
	isImpossible = obj.isImpossible;
	return *this;
}

bool Int::isValidNumber(const string& s, long num, const string& end)
{
	if (s == "nan" || s == "nanf")
		return false;
	if (s == "inf" || s == "-inf" || s == "+inf")
		return false;
	if (s == "inff" || s == "-inff" || s == "+inff")
		return false;
	if (s == "")
		return false;
	if (end != "f" && end != "")
		return false;
	if (errno == ERANGE)
		return false;
	if (num > 2147483647)
		return false;
	if (num < -2147483648)
		return false;
	return true;
}

Int::Int (const string& s) 
{
	char *end;
	long num = std::strtol(s.c_str(), &end, 10);
	
	number = 0;
	isImpossible = false;
	if (!isValidNumber(s, num, end))
		isImpossible = true;
	else
		number = num;
}

Int::Int (const Char& c)
{
	number = 0;
	isImpossible = false;
	number = static_cast<int>(c.Character());
}

Int::Int (const Float& f)
{
	number = 0;
	isImpossible = false;

	if ((long)f.Number() > 2147483647 || (long)f.Number() < -2147483648 
		|| errno == ERANGE || f.IsImpossible())
		isImpossible = true;
	else
		number = static_cast<int>(f.Number());
}

Int::Int (const Double& d)
{
	number = 0;
	isImpossible = false;

	if (d.Number() > 2147483647 || d.Number() < -2147483648 || d.IsImpossible())
		isImpossible = true;
	else
		number = static_cast<int>(d.Number());
}

string Int::toString() const {
	if (isImpossible)
		return "Imposible";
	std::stringstream s;
	s << number;
	return s.str();
}

std::ostream& operator<<(std::ostream& os, Int& num) 
{
	os << num.toString();
	return os;
}

int Int::Number() const
{
	return number;
}

bool Int::IsImpossible() const
{
	return isImpossible;
}
