#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	cout << "WrongCat object created\n";
}

WrongCat::~WrongCat()
{
	cout << "WrongCat object destroyde\n";
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal(obj.type)
{
	cout << "WrongCat object copyed\n";
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	type = obj.type;
	cout << "Dog object use assignment(=) operator\n";
	return *this;
}

void WrongCat::makeSound() const
{
	cout << "WrongCat say Meow\n";
}
