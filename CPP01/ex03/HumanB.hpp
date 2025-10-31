#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	Weapon *weapen;
	string name;
public:
	HumanB(string name);
	~HumanB();
	void setWeapon(Weapon weapen);
	void attack();
};

#endif