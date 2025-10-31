#include "Zombie.hpp"

void Zombie::randomChump( string name )
{
	Zombie z(name);
	z.announce();
}