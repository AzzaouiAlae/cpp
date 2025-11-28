#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	cout << "Cat object created\n";
}

Cat::~Cat()
{
	cout << "Cat object destroyde\n";
}

Cat::Cat(const Cat& obj): Animal(obj.type)
{
	cout << "Cat object copyed\n";
}

Cat& Cat::operator=(const Cat &obj)
{
	type = obj.type;
	cout << "Dog object use assignment(=) operator\n";
	return *this;
}

void Cat::makeSound() const
{
	cout << "Cat say Meow\n";
}
