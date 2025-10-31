#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie* zombies = Zombie::zombieHorde(n, "Zx");

	for(int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
