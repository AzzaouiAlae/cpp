#include "Char.hpp"
#include <cstdlib>
#include <cerrno>
#include <cstring>

Char::Char()
{
	c = 0;
	isImpossible = true;
}

Char::~Char()
{}

Char::Char(const Char& ch)
{
	c = ch.c;
	isImpossible = ch.isImpossible;
	isNonDisplayable = ch.isNonDisplayable;
}

Char& Char::operator=(const Char& ch)
{
	c = ch.c;
	isImpossible = ch.isImpossible;
	isNonDisplayable = ch.isNonDisplayable;
	return *this;
}

bool Char::isValidNumber(const string& s, float num ,const string& end)
{
	if (num > 255 || num < 0)
		return false;
	if (s == "")
		return false;
	if (s.length() == 1)
		return true;
	if (end != "f" && end != "")
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

Char::Char (const string& s) 
{
	char *end;
	float num = std::strtof(s.c_str(), &end);

	c = '\0';
	isImpossible = false;
	isNonDisplayable = false;
	
	if (s.length() == 1 && !isdigit(s[0]))
		num = s[0];
	if (!isValidNumber(s, num, end))
		isImpossible = true;
	else if (!isprint((char)num))
		isNonDisplayable = true;
	else
		c = (char)num;
}

Char::Char (const Int& num)
{
	c = '\0';
	isImpossible = false;
	isNonDisplayable = false;

	if (num.Number() > 255 || num.Number() < 0)
		isImpossible = true;
	else if (!isprint((char)num.Number()))
		isNonDisplayable = true;
	else
		c = static_cast<char>(num.Number());
}

Char::Char (const Float& num)
{
	c = '\0';
	isImpossible = false;
	isNonDisplayable = false;

	if (num.Number() > 255 || num.Number() < 0)
		isImpossible = true;
	else if (!isprint((char)num.Number()))
		isNonDisplayable = true;
	else
		c = static_cast<char>(num.Number());
}

Char::Char (const Double& num)
{
	c = '\0';
	isImpossible = false;
	isNonDisplayable = false;

	if (num.Number() > 255 || num.Number() < 0 || num.IsImpossible())
		isImpossible = true;
	else if (!isprint((char)num.Number()))
		isNonDisplayable = true;
	else
		c = static_cast<char>(num.Number());
}

string Char::toString() const {
	if (isImpossible)
		return "Imposible";
	else if (isNonDisplayable)
		return "Non Displayable";
	std::stringstream s;
	s << "'" << c << "'";
	return s.str();
}

std::ostream& operator<<(std::ostream& os, Char& ch) 
{
	os << ch.toString();
	return os;
}

char Char::Character() const
{
	return c;
}

bool Char::IsImpossible() const
{
	return isImpossible;
}