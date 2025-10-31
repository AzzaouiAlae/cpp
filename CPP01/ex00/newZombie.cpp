#include "Zombie.hpp"

Zombie* Zombie::newZombie( string name )
{
	Zombie* z = new Zombie(name);
	return z;
}
