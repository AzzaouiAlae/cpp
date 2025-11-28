#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl
#define string std::string

class ClapTrap {
	string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
	ClapTrap();
public:
	ClapTrap(string name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap();
	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void PrintStatus();
};


#endif