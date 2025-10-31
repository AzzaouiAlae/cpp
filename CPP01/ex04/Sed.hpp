#ifndef SED_HPP
#define SED_HPP
#include <iostream>
#include <bits/stdc++.h>

#define cout std::cout
#define string std::string
#define endl std::endl

class Sed {
	string file;
	std::ifstream *filein;
	std::ofstream *fileout;
public:
	~Sed();
	bool IsOpen();
	Sed(string file);
	static bool CheckInput(char *input[]);
	bool replace(string s1, string s2);
};

#endif