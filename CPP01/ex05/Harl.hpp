#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

#define cout std::cout
#define string std::string
#define endl std::endl

class Harl {
	void debug();
	void info();
	void warning();
	void error();
	std::pair<string, void (Harl::*)()> pairs[4];
	void InitPairs();
	void InitPair(int i, string name, void (Harl::*comlainType)());
public:
	void complain(string level);
	Harl();
};

#endif