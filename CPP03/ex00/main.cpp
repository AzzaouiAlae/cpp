#include "ClapTrap.hpp"

int main()
{
	ClapTrap obj("robot");
	ClapTrap obj1("robot1");
	ClapTrap obj2("robot2");
	ClapTrap obj3("robot3");

	cout << "\n";
	obj.attack("robot1");
	obj1.takeDamage(1);
	obj1.beRepaired(1);

	cout << "\n";
	obj.attack("robot2");
	obj2.takeDamage(1);
	obj2.beRepaired(1);

	cout << "\n";
	obj.attack("robot3");
	obj3.takeDamage(1);
	obj3.beRepaired(1);

	cout << "\n";
	obj.PrintStatus();
	obj1.PrintStatus();
	obj2.PrintStatus();
	obj3.PrintStatus();

	cout << "\nConsume all the energy points and try to repaired\n";
	for (int i = 0; i < 7; i++)
		obj.attack("robot1");
	obj.beRepaired(10);
	obj.PrintStatus();

	cout << "\nConsume all the hit points and try to repaired\n";
	obj1.takeDamage(10);
	obj1.beRepaired(10);
	obj1.PrintStatus();

	cout << "\n";
	return 0;
}
