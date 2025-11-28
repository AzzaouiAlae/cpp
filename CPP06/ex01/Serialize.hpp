#pragma once

#include <iostream>
#include <stdint.h>
#define string std::string
#define cout std::cout
#define endl std::endl

class Data;

class Serialize 
{
	Serialize();
	~Serialize();
	Serialize(const Serialize& obj);
	Serialize& operator=(const Serialize& obj);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
