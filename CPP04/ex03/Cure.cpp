#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& obj): AMateria(obj.type)
{
}

Cure& Cure::operator=(const Cure& obj)
{
	(void)obj;
	type = "cure";
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << 
			target.getName() << "’s wounds *" << endl;
}