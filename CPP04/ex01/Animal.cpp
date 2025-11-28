#include "Animal.hpp"

Animal::Animal(): type("unknown")
{
	cout << "Animal object created\n";
}

Animal::~Animal()
{
	cout << "Animal object destroyde\n";
}

Animal::Animal(const Animal& obj)
{
	type = obj.type;
	cout << "Animal object copyed\n";
}

Animal& Animal::operator=(const Animal &obj)
{
	type = obj.type;
	cout << "Animal object use assignment(=) operator\n";
	return *this;
}

void Animal::makeSound() const
{
	cout << "Animal making unknown sound\n";
}

Animal::Animal(const string& type): type(type)
{
	cout << "Animal object created\n";
}

string Animal::getType() const
{
	return type;
}