#include "Zombie.hpp"

void Zombie::announce( void )
{
	cout << name << ": BraiiiiiiinnnzzzZ...\n";
} 

Zombie::Zombie (string name) 
{
	this->name = name;
}

Zombie::~Zombie()
{
	cout << "Zombie " << name << " died\n";
}

Zombie::Zombie ()
{

}

void Zombie::SetName(string name)
{
	this->name = name;
}
