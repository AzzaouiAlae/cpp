#include "AAnimal.hpp"

AAnimal::AAnimal(): type("unknown")
{
	cout << "AAnimal object created\n";
}

AAnimal::~AAnimal()
{
	cout << "AAnimal object destroyde\n";
}

AAnimal::AAnimal(const AAnimal& obj)
{
	type = obj.type;
	cout << "AAnimal object copyed\n";
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
	type = obj.type;
	cout << "AAnimal object use assignment(=) operator\n";
	return *this;
}

AAnimal::AAnimal(const string& type): type(type)
{
	cout << "AAnimal object created\n";
}

string AAnimal::getType() const
{
	return type;
}