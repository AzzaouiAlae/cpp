#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain* brain;
public:
	Cat();
	~Cat();
	Cat(const Cat& obj);
	Cat& operator=(const Cat &obj);
	void makeSound() const;
	Brain* GetBrain();
	void SetBrain(Brain* brain);
};

