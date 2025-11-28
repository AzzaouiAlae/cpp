#include "DiamondTrap.hpp"

int main()
{
	{
		DiamondTrap obj("robot");
		cout << "\n";
	}
	cout << "---------------------9\n";
	{
		DiamondTrap obj("robot2");
		cout << "\n";
		DiamondTrap obj2 = obj;
		cout << "\n";
	}
	cout << "---------------------16\n";
	{
		DiamondTrap obj("robot4");
		cout << "\n";
		DiamondTrap obj2("robot5");
		cout << "\n";
		obj = obj2;
		cout << "\n";
	}
	cout << "---------------------25\n";
	{
		DiamondTrap obj("robot6");
		cout << "\n";
		obj.whoAmI();
		cout << "\n";
	}
	cout << "---------------------32\n";
	{
		DiamondTrap obj("robot7");
		cout << "\n";
		obj.attack("any robot");
		cout << "\n";
	}
	cout << "---------------------41\n";
	{
		DiamondTrap obj("robot8");
		cout << "\n";
		obj.takeDamage(20);
		obj.PrintStatus();
		cout << "\n";
	}
	cout << "---------------------49\n";
	{
		DiamondTrap obj("robot9");
		cout << "\n";
		obj.beRepaired(20);
		obj.PrintStatus();
		cout << "\n";
	}
	cout << "---------------------57\n";
	{
		DiamondTrap obj("robot10");
		cout << "\n";
		obj.beRepaired(20);
		obj.PrintStatus();
		cout << "\n";
	}
	return 0;
}
