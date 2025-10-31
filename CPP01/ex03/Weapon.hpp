#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

#define cout std::cout
#define string std::string
#define endl std::endl

class Weapon 
{
	string type;
public:
	Weapon(string type);
	static Weapon *CreateNewWeapon(string type);
	string getType();
	void setType(string type);
};

#endif
