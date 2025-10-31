#include "HumanB.hpp"

void HumanB::setWeapon(Weapon weapen)
{
	this->weapen = Weapon::CreateNewWeapon(weapen.getType());
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

HumanB::~HumanB()
{
	delete weapen;
}
