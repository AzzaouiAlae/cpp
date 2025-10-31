#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, string name )
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].SetName(name);
	return zombies;
}
