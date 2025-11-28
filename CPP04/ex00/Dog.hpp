#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog& operator=(const Dog &obj);
	Dog(const Dog& obj);
	void makeSound() const;
};

