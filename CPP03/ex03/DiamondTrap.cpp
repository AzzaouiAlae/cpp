#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{}

void DiamondTrap::attack(const string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (FragTrap::hitPoints == 0)
		return;
	if (amount < (unsigned int)FragTrap::hitPoints)
	{
		cout << "DiamondTrap "<< name <<" take " << amount << " of damage\n";
		FragTrap::hitPoints -= amount;
	}
	else
	{
		cout << "DiamondTrap "<< name <<" take " << FragTrap::hitPoints << " of damage\n";
		FragTrap::hitPoints = 0;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (ScavTrap::energyPoints == 0 || FragTrap::hitPoints == 0)
		return;
	ScavTrap::energyPoints--;
	cout << "FragTrap "<< name <<" repaire " << amount << 
		" of damage\n";
	FragTrap::hitPoints += amount;
}

void DiamondTrap::PrintStatus()
{
	cout << "DiamondTrap: " << name << " has: "<< FragTrap::hitPoints << " hit points, " << 
	ScavTrap::energyPoints << " energy points, " << FragTrap::attackDamage << " attack damage."
	<< endl;
}

DiamondTrap::DiamondTrap(const string& name): ClapTrap(name + "_clap_name"),
FragTrap(name), ScavTrap(name), name(name)
{
	cout << "DiamondTrap "<< name << " created\n";
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap "<< name << " destroyde\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : 
ClapTrap(obj.name + "_clap_name", obj.hitPoints, obj.energyPoints, obj.attackDamage),
FragTrap(obj.name), ScavTrap(obj.name), name(obj.name)
{
	cout << "Copy DiamondTrap "<< obj.name << " to create a new one\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	this->name = obj.name;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	this->hitPoints = obj.hitPoints;
	cout << "DiamondTrap "<< name << " copyed\n";
	return *this;
}

void DiamondTrap::whoAmI()
{
	cout << "DiamondTrap name is: " << name << " | "
	"ClapTrap name is: " << ClapTrap::name << endl;
}
