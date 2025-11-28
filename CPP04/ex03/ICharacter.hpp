#pragma once
#include "AMateria.hpp"
#include <iostream>
#define string std::string
#define cout std::cout
#define endl std::endl

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
