#pragma once
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl
#define string std::string

class WrongAnimal {
protected:
	string type;
	WrongAnimal(const string& type);
public:
	string getType() const;
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator=(const WrongAnimal &obj);
	void makeSound() const;
};

