#pragma once

#include <iostream>
#define string std::string
#define cout std::cout
#define endl std::endl

class Data
{
public:
	Data();
	~Data();
	Data(const Data& obj);
	Data& operator=(const Data& obj);
	int Number;
};