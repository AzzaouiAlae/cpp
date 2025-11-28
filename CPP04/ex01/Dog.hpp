#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain* brain;
	int i;
public:
	Dog();
	~Dog();
	Dog& operator=(const Dog &obj);
	Dog(const Dog& obj);
	void makeSound() const;
	void makeSound2();
	Brain* GetBrain();
	void SetBrain(Brain* brain);
};

