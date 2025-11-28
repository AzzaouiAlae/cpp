#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	brain = new Brain();
	cout << "Dog object created\n";
}

Dog::~Dog()
{
	delete brain;
	cout << "Dog object destroyde\n";
}

Dog::Dog(const Dog& obj): Animal(obj.type)
{
	brain = new Brain();
	*(this->brain) = *(obj.brain);
	cout << "Dog object copyed\n";
}

Dog& Dog::operator=(const Dog &obj)
{
	type = obj.type;
	*brain = *(obj.brain);
	cout << "Dog object use assignment(=) operator\n";
	return *this;
}

void Dog::makeSound() const
{
	cout << "Dog is barking\n";
}

void Dog::makeSound2()
{
	i = 10;
	cout << "Dog is barking\n" << i << endl;
}

Brain* Dog::GetBrain()
{
	return brain;
}

void Dog::SetBrain(Brain *brain)
{
	delete this->brain;
	this->brain = brain;
}