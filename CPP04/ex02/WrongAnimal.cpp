#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("unknown")
{
	cout << "WrongAnimal object created\n";
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal object destroyde\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	type = obj.type;
	cout << "WrongAnimal object copyed\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	type = obj.type;
	cout << "WrongAnimal object use assignment(=) operator\n";
	return *this;
}

void WrongAnimal::makeSound() const
{
	cout << "WrongAnimal making unknown sound\n";
}

WrongAnimal::WrongAnimal(const string& type): type(type)
{
	cout << "WrongAnimal object created\n";
}

string WrongAnimal::getType() const
{
	return type;
}