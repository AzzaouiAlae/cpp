#include "Weapon.hpp"

Weapon::Weapon(string type)
{
	this->type = type;
}
string Weapon::getType()
{
	return type;
}
void Weapon::setType(string type)
{
	this->type = type;
}

Weapon* Weapon::CreateNewWeapon(string type)
{
	return new Weapon(type);
}