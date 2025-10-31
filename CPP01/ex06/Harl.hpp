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
	int level;
	string pairs[4];
	int SetLevel(string level);
	void InitPairs();
	void InitPair(int i, string name);
public:
	void complain();
	Harl(string level);
};

#endif