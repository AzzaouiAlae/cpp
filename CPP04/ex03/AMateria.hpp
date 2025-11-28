#pragma once
#include "ICharacter.hpp"
#include <iostream>
#define string std::string
#define cout std::cout
#define endl std::endl

class ICharacter;

class AMateria
{
protected:
	string type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria &obj);
	AMateria& operator=(const AMateria &obj);
	AMateria(string const & type);
	string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
