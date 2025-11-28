#pragma once
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl

class AAnimal {
	protected:
	string type;
public:
	AAnimal();
	AAnimal(const string& type);
	string getType() const;
	virtual ~AAnimal();
	AAnimal(const AAnimal& obj);
	AAnimal& operator=(const AAnimal &obj);
	virtual void makeSound() const = 0;
};
