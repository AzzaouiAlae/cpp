#pragma once
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl

class Animal {
protected:
	string type;
public:
	Animal(const string& type);
	string getType() const;
	Animal();
	virtual ~Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal &obj);
	virtual void makeSound() const;
};
