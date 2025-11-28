#include "FragTrap.hpp"

int main()
{
	// {
	// 	FragTrap obj("robot");
	// 	cout << "\n";
	// }
	// cout << "---------------------9\n";
	// {
	// 	FragTrap obj("robot2");
	// 	cout << "\n";
	// 	FragTrap obj2 = obj;
	// 	cout << "\n";
	// }
	// cout << "---------------------16\n";
	// {
	// 	FragTrap obj("robot4");
	// 	cout << "\n";
	// 	FragTrap obj2("robot5");
	// 	cout << "\n";
	// 	obj = obj2;
	// 	cout << "\n";
	// }
	// cout << "---------------------25\n";
	// {
	// 	FragTrap obj("robot6");
	// 	cout << "\n";
	// 	obj.highFivesGuys();
	// 	cout << "\n";
	// }
	// cout << "---------------------32\n";
	// {
	// 	FragTrap obj("robot7");
	// 	cout << "\n";
	// 	obj.attack("any robot");
	// 	cout << "\n";
	// 	obj.ClapTrap::attack("other robot");
	// 	cout << "\n";
	// }
	// cout << "---------------------41\n";
	// {
	// 	FragTrap obj("robot8");
	// 	cout << "\n";
	// 	obj.takeDamage(20);
	// 	obj.PrintStatus();
	// 	cout << "\n";
	// }
	// cout << "---------------------49\n";
	// {
	// 	FragTrap obj("robot9");
	// 	cout << "\n";
	// 	obj.beRepaired(20);
	// 	obj.PrintStatus();
	// 	cout << "\n";
	// }
	// cout << "---------------------57\n";
	// {
	// 	FragTrap obj("robot10");
	// 	cout << "\n";
	// 	obj.beRepaired(20);
	// 	obj.PrintStatus();
	// 	cout << "\n";
	// }
	ClapTrap *obj = new FragTrap("name");
	obj->attack("someone");

	delete obj;
	return 0;
}
