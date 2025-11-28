#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain())
{
	cout << "Cat object created\n";
}

Cat::~Cat()
{
	delete brain;
	cout << "Cat object destroyde\n";
}

Cat::Cat(const Cat& obj): Animal(obj.type)
{
	brain = new Brain();
	*(this->brain) = *(obj.brain);
	cout << "Cat object copyed\n";
}

Cat& Cat::operator=(const Cat &obj)
{
	type = obj.type;
	*brain = *(obj.brain);
	cout << "Dog object use assignment(=) operator\n";
	return *this;
}

void Cat::makeSound() const
{
	cout << "Cat say Meow\n";
}
