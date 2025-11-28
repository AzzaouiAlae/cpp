#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(const Data& obj) 
{
	Number = obj.Number; 
}
Data& Data::operator=(const Data& obj)
{
	Number = obj.Number;
	return *this;
}
