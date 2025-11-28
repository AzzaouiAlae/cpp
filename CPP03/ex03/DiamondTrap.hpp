#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : protected FragTrap, protected ScavTrap
{
	string name;
	DiamondTrap();
public:
	~DiamondTrap();
	DiamondTrap(const string& name);
	DiamondTrap(const DiamondTrap& obj);
	DiamondTrap& operator=(const DiamondTrap& obj);
	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void PrintStatus();
	void whoAmI();
};

#endif