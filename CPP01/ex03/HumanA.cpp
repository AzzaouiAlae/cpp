#include "HumanA.hpp"

void HumanA::setWeapon(Weapon &weapen)
{
	this->weapen = weapen;
}

HumanA::HumanA(string name, Weapon &weapen) : weapen(weapen)
{
	this->name = name;
}

void HumanA::attack()
{
	cout << name << " attacks with their " << weapen.getType()
		<< endl;
}
