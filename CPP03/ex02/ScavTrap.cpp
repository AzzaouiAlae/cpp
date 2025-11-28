#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{}

ScavTrap::ScavTrap(const string& name): ClapTrap(name, 100, 50, 20)
{
	cout << "ScavTrap "<< name << " created\n";
}

void ScavTrap::attack(const string& target)
{
	if (energyPoints == 0)
		return;
	energyPoints--;
	cout << "ScavTrap "<< name <<" attacks "<< target << 
		", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
		return;
	if (amount < (unsigned int)hitPoints)
	{
		cout << "ScavTrap "<< name <<" take " << amount << " of damage\n";
		hitPoints -= amount;
	}
	else
	{
		cout << "ScavTrap "<< name <<" take " << hitPoints << " of damage\n";
		hitPoints = 0;
	}
}

void ScavTrap::PrintStatus()
{
	cout << "ScavTrap: " << name << " has: "<< hitPoints << " hit points, " << 
	energyPoints << " energy points, " << attackDamage << " attack damage."
	<< endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0 || hitPoints == 0)
		return;
	energyPoints--;
	cout << "ScavTrap "<< name <<" repaire " << amount << 
		" of damage\n";
	hitPoints += amount;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap "<< name << " destroyde\n";
}

void ScavTrap::guardGate()
{
	cout << "ScavTrap: " << name << " is now in Gate keeper mode\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj): 
ClapTrap(obj.name, obj.hitPoints, obj.energyPoints, obj.attackDamage)
{
	cout << "ScavTrap: " << name << " copyed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	cout << "ScavTrap: " << name << " call assignment = operator\n";
	this->name = obj.name;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	this->hitPoints = obj.hitPoints;
	return *this;
}
