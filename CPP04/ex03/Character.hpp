#pragma once
#include "ICharacter.hpp"
class Character : public ICharacter
{
	string name;
	AMateria *slots[4];
public:
	Character(const string& name);
	~Character();
	Character(const Character &obj);
	Character& operator=(const Character& obj);
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	string const & getName() const;
};
