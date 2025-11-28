#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice& obj): AMateria(obj.type)
{
}

Ice& Ice::operator=(const Ice& obj)
{
	(void)obj;
	type = "ice";
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << 
			target.getName() << " *" << endl;
}
