#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

#define string std::string
#define cout std::cout
class Zombie 
{
	string name;
public:
	void SetName(string name);
	Zombie ();
	Zombie (string name);
	void announce( void ); 
	~Zombie();
	static Zombie* zombieHorde( int N, string name );
};

#endif