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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"

void Harl::complain()
{
	switch (level)
	{
	case 1:
		debug();
	case 2:
		info();
	case 3:
		warning();
	case 4:
		error();
	default:
		break;
	}
}
#pragma GCC diagnostic pop

void Harl::InitPair(int i, string name) 
{
	pairs[i] = name;
}

void Harl::InitPairs()
{
	InitPair(0, "DEBUG");
	InitPair(1, "INFO");
	InitPair(2, "WARNING");
	InitPair(3, "ERROR");
}

int Harl::SetLevel(string level)
{
	for(int i = 0; i < 4; i++)
	{
		if (level == pairs[i])
			return i + 1;
	}
	return -1;
}

Harl::Harl(string level)
{
	InitPairs();
	this->level = SetLevel(level);
}
