#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	ScavTrap();
public:
	ScavTrap(const ScavTrap& obj);
	ScavTrap& operator=(const ScavTrap& obj);
	~ScavTrap();
	ScavTrap(const string& name);
	void guardGate();
	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void PrintStatus();
};

#endif