#include "Harl.hpp"

void Harl::debug() {
	cout << "[ DEBUG ]\n" "I love having"
		" extra bacon for my 7XL-double-cheese"
		"-triple-pickle-special-ketchup burger.\n"
		"I really do!\n\n";
}
void Harl::info() {
	cout << "[ INFO ]\n" "I cannot believe adding extra bacon costs more money.\n"
		"You didn’t put enough bacon in my burger!\n" 
		"If you did, I wouldn’t be asking for more!\n\n";
}
void Harl::warning() {
	cout << "[ WARNING ]\n" "I think I deserve to have some extra bacon for free."
		"\nI’ve been coming for years, whereas you started working here just last month.\n\n";
}
void Harl::error() {
	cout << "[ ERROR ]\n" "This is unacceptable!\n"
		"I want to speak to the manager now.\n\n";
}

void Harl::complain(string level) {
	for(int i = 0; i < 4; i++)
	{
		if (level == pairs[i].first)
		{
			(this->*pairs[i].second)();
			return;
		}
	}
}

void Harl::InitPair(int i, string name, void (Harl::*func)()) 
{
	pairs[i].first = name;
	pairs[i].second = func;
}

void Harl::InitPairs()
{
	InitPair(0, "DEBUG", &Harl::debug);
	InitPair(1, "INFO", &Harl::info);
	InitPair(2, "WARNING", &Harl::warning);
	InitPair(3, "ERROR", &Harl::error);
}

Harl::Harl()
{
	InitPairs();
}
