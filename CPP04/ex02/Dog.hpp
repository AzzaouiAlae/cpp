#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	Brain* brain;
public:
	Dog();
	~Dog();
	Dog& operator=(const Dog &obj);
	Dog(const Dog& obj);
	void makeSound() const;
	Brain* GetBrain();
	void SetBrain(Brain* brain);
};

