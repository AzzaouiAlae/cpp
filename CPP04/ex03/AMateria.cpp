#include "ICharacter.hpp"

AMateria::AMateria(string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{
}

string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
AMateria::AMateria()
{
}
AMateria::AMateria(const AMateria &obj)
{
	type = obj.type;
}
AMateria& AMateria::operator=(const AMateria &obj)
{
	type = obj.type;
	return *this;
}
