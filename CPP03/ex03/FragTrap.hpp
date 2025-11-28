#ifndef FRAGTRAP_CPP
#define FRAGTRAP_CPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap();
public:
	~FragTrap();
	FragTrap(const string& name);
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	void highFivesGuys(void);
	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void PrintStatus();
};

#endif