#include "Float.hpp"
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iomanip>
#include <cfloat>
#include <limits>

Float::Float()
{
	number = 0;
	isImpossible = true;
}

Float::~Float()
{}

Float::Float(const Float& obj)
{
	number = obj.number;
	isImpossible = obj.isImpossible;
}

Float& Float::operator=(const Float& obj)
{
	number = obj.number;
	isImpossible = obj.isImpossible;
	return *this;
}

bool Float::isValidNumber(const string& s, const string& end)
{
	if (s == "")
		return false;
	if (end != "f" && end != "")
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

Float::Float (const string& s)
{
	char *end;
	float num = std::strtof(s.c_str(), &end);

	number = 0;
	isImpossible = false;
	if (!isValidNumber(s, end))
		isImpossible = true;
	else
		number = num;
}

Float::Float (const Int& num)
{
	number = 0;
	isImpossible = false;

	number = static_cast<float>(num.Number());
}

Float::Float (const Double& d)
{
	number = 0;
	isImpossible = false;

	if (std::numeric_limits<float>::max() < d.Number() || d.IsImpossible())
		isImpossible = true;
	else if (-std::numeric_limits<float>::max() > d.Number())
		isImpossible = true;
	else
		number = static_cast<float>(d.Number());
}

Float::Float (const Char& c)
{
	number = 0;
	isImpossible = false;

	number = static_cast<float>(c.Character());
}

string Float::toString() const {
	if (isImpossible)
		return "Imposible";
	std::stringstream s;
	s << std::fixed;
	s << number << 'f';
	return s.str();
}

std::ostream& operator<<(std::ostream& os, Float& num) 
{
	os << num.toString();
	return os;
}

float Float::Number() const {
	return number;
}

bool Float::IsImpossible() const
{
	return isImpossible;
}
