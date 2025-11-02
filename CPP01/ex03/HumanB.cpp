#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& weapen)
{
	this->weapen = &weapen;
}

HumanB::HumanB(string name)
{
	weapen = NULL;
	this->name = name;
}

void HumanB::attack()
{
	if (weapen == NULL)
		return;
	cout << name << " attacks with their " << weapen->getType()
		<< endl;
}


