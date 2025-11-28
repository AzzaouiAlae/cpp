#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	ScavTrap();
public:
	~ScavTrap();
	ScavTrap(const string& name);
	ScavTrap(const ScavTrap& obj);
	ScavTrap& operator=(const ScavTrap& obj);
	void guardGate();
	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void PrintStatus();
};

#endif