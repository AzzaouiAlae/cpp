#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{}

ClapTrap::ClapTrap(const string& name, int hitPoints, int energyPoints, int attackDamage):
		name(name), hitPoints(hitPoints), energyPoints(energyPoints),
		attackDamage(attackDamage)
{
	cout << "ClapTrap "<< name << " created\n";
}

ClapTrap::ClapTrap(string name) : name(name),
		hitPoints(10), energyPoints(10),
		attackDamage(0)
{
	cout << "ClapTrap "<< name << " created\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name(obj.name), hitPoints(obj.hitPoints),
energyPoints(obj.energyPoints), attackDamage(obj.attackDamage) 

{
	cout << "Copy ClapTrap "<< obj.name << " to create a new one\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	this->name = obj.name;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	this->hitPoints = obj.hitPoints;
	cout << "ClapTrap "<< name << " copyed\n";
	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap "<< name << " destroyde\n";
}

void ClapTrap::attack(const string& target)
{
	if (energyPoints == 0 || hitPoints == 0)
		return;
	energyPoints--;
	cout << "ClapTrap "<< name <<" attacks "<< target << 
		", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
		return;
	if (amount < (unsigned int)hitPoints)
	{
		cout << "ClapTrap "<< name <<" take " << amount << " of damage\n";
		hitPoints -= amount;
	}
	else
	{
		cout << "ClapTrap "<< name <<" take " << hitPoints << " of damage\n";
		hitPoints = 0;
	}
}
void ClapTrap::PrintStatus()
{
	cout << "ClapTrap: " << name << " has: "<< hitPoints << " hit points, " << 
	energyPoints << " energy points, " << attackDamage << " attack damage."
	<< endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0 || hitPoints == 0)
		return;
	energyPoints--;
	cout << "ClapTrap "<< name <<" repaire " << amount << 
		" of damage\n";
	hitPoints += amount;
}

