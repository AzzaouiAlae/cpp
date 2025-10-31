#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

#define string std::string
#define cout std::cout
class Zombie 
{
	string name;
public:
	Zombie (string name);
	void announce( void ); 
	static Zombie* newZombie( string name );
	static void randomChump( string name );
	~Zombie();
};

#endif