#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	Weapon &weapen;
	string name;
public:
	void setWeapon(Weapon &weapen);
	HumanA(string name, Weapon &weapen);
	void attack();
};

#endif