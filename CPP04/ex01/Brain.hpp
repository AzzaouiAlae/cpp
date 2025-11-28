#pragma once
#include <iostream>
#define string std::string
#define cout std::cout
#define endl std::endl

class Brain
{
public:
	string ideas[100];
	Brain();
	~Brain();
	Brain(const Brain& obj);
	Brain &operator=(const Brain& obj);
};