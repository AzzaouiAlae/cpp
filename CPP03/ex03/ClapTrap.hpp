#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl
#define string std::string

class ClapTrap {
protected:
	ClapTrap();
	ClapTrap(const string& name, int hitPoints, int energyPoints, int attackDamage);
	string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	ClapTrap(string name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap();
	virtual void attack(const string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	virtual void PrintStatus();
};

#endif