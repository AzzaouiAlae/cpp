#include "Character.hpp"

Character::Character(const string& name): name(name)
{
	for (size_t i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

Character::Character(const Character &obj)
{
	name = obj.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (obj.slots[i])
			slots[i] = obj.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

Character& Character::operator=(const Character& obj)
{
	name = obj.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
		if (obj.slots[i])
			slots[i] = obj.slots[i]->clone();
		else
			slots[i] = NULL;
	}
	return *this;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return;
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || !slots[idx])
		return;
	slots[idx]->use(target);
	delete slots[idx];
	unequip(idx);
}

string const & Character::getName() const
{
	return name;
}