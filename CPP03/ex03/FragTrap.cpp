#include "FragTrap.hpp"

FragTrap::FragTrap()
{}

FragTrap::FragTrap(const string& name): ClapTrap(name, 100, 50, 20)
{
	cout << "FragTrap "<< name << " created\n";
}

void FragTrap::attack(const string& target)
{
	if (energyPoints == 0)
		return;
	energyPoints--;
	cout << "FragTrap "<< name <<" attacks "<< target << 
		", causing " << attackDamage << " points of damage!\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
		return;
	if (amount < (unsigned int)hitPoints)
	{
		cout << "FragTrap "<< name <<" take " << amount << " of damage\n";
		hitPoints -= amount;
	}
	else
	{
		cout << "FragTrap "<< name <<" take " << hitPoints << " of damage\n";
		hitPoints = 0;
	}
}

void FragTrap::PrintStatus()
{
	cout << "FragTrap: " << name << " has: "<< hitPoints << " hit points, " << 
	energyPoints << " energy points, " << attackDamage << " attack damage."
	<< endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0 || hitPoints == 0)
		return;
	energyPoints--;
	cout << "FragTrap "<< name <<" repaire " << amount << 
		" of damage\n";
	hitPoints += amount;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap "<< name << " destroyde\n";
}

void FragTrap::highFivesGuys(void)
{
	cout << "FragTrap: " << name << " try to make 'High Five'\n";
}

FragTrap::FragTrap(const FragTrap& obj): 
ClapTrap(obj.name, obj.hitPoints, obj.energyPoints, obj.attackDamage)
{
	cout << "FragTrap: " << name << " copyed\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	cout << "FragTrap: " << name << " call assignment = operator\n";
	this->name = obj.name;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	this->hitPoints = obj.hitPoints;
	return *this;
}
