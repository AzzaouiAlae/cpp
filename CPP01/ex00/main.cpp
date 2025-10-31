#include "Zombie.hpp"

int main()
{
	Zombie *z = Zombie::newZombie("Z1");
	z->announce();
	delete z;

	Zombie::randomChump("Z2");
	Zombie::randomChump("Z3");

	Zombie z5("Z5");
	Zombie z4("Z4");
	return 0;
}
