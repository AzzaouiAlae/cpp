#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap obj("robot");
		cout << "\n";
	}
	cout << "---------------------9\n";
	{
		ScavTrap obj("robot2");
		cout << "\n";
		ScavTrap obj2 = obj;
		cout << "\n";
	}
	cout << "---------------------16\n";
	{
		ScavTrap obj("robot4");
		cout << "\n";
		ScavTrap obj2("robot5");
		cout << "\n";
		obj = obj2;
		cout << "\n";
	}
	cout << "---------------------25\n";
	{
		ScavTrap obj("robot6");
		cout << "\n";
		obj.guardGate();
		cout << "\n";
	}
	cout << "---------------------32\n";
	{
		ScavTrap obj("robot7");
		cout << "\n";
		obj.attack("any robot");
		cout << "\n";
		obj.ClapTrap::attack("other robot");
		cout << "\n";
	}
	cout << "---------------------41\n";
	{
		ScavTrap obj("robot8");
		cout << "\n";
		obj.takeDamage(20);
		obj.PrintStatus();
		cout << "\n";
	}
	cout << "---------------------49\n";
	{
		ScavTrap obj("robot9");
		cout << "\n";
		obj.beRepaired(20);
		obj.PrintStatus();
		cout << "\n";
	}
	cout << "---------------------57\n";
	{
		ScavTrap obj("robot10");
		cout << "\n";
		obj.beRepaired(20);
		obj.PrintStatus();
		cout << "\n";
	}
	return 0;
}
