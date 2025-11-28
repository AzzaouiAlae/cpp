#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	cout << "Dog object created\n";
}

Dog::~Dog()
{
	cout << "Dog object destroyde\n";
}

Dog::Dog(const Dog& obj): Animal(obj.type)
{
	cout << "Dog object copyed\n";
}

Dog& Dog::operator=(const Dog &obj)
{
	type = obj.type;
	cout << "Dog object use assignment(=) operator\n";
	return *this;
}

void Dog::makeSound() const
{
	cout << "Dog is barking\n";
}
