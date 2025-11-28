#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

#define cout std::cout
#define string std::string
#define endl std::endl

class Weapon 
{
	string type;
public:
	Weapon(string type);
	const string& getType() const;
	void setType(string type);
};

const char *str = "2132";
char const *str;
#endif
