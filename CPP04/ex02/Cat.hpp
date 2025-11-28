#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
