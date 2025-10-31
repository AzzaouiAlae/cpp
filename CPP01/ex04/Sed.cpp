#include "Sed.hpp"

bool Sed::CheckInput(char *input[])
{
	int i = 0;

	while (input[i])
	{
		if (i < 3 && input[i][0] == '\0')
		{
			if (i == 0)
				cout << "Error: filename cannot be empty\n";
			else if (i == 1)
				cout << "Error: S1 cannot be empty\n";
			return false;
		}
		if (i >= 3)
		{
			cout << "Too many arguments\n";
			return false;
		}
		i++;
	}
	if (i != 3)
		cout << "Too few arguments\n";
	return i == 3;
}

bool Sed::IsOpen()
{
	return filein && filein->is_open() && fileout && fileout->is_open();
}

bool Sed::replace(string s1, string s2)
{
	char s[1024];
	std::streamsize len = 1023, buffSize = 1023, i;
	
	while (len == buffSize)
	{
		len = filein->readsome(s, buffSize);
		s[len] = '\0';
		string str(s);
		while (str != "")
		{
			i = str.find(s1);
			if (i < 0)
				break;
			fileout->write(str.c_str(), i);
			fileout->write(s2.c_str(), s2.size());
			str = str.substr(i + s1.length());
		}
		fileout->write(str.c_str(), str.size());
	}
	return true;
}

Sed::Sed(string file)
{
	filein = new std::ifstream(file.c_str());
	if (filein->is_open())
	{
		this->file = file + ".replace";
		fileout = new std::ofstream(this->file.c_str());
	}
	else
		fileout = NULL;
}

Sed::~Sed()
{
	if (fileout)
		delete fileout;
	if (filein)
		delete filein;
}
