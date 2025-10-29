#ifndef PHONEBOOKCLI_HPP
#define PHONEBOOKCLI_HPP

#include "PhoneBook.hpp"
#define endl std::endl

class PhoneBookCLI {
	PhoneBook _phoneBook;
	void DrawOptionScreen();
	void DrawAddScreen();
	void DrawSearchScreen();
	void PrintContact(Contact contact, int index);
	void PrintSubStr(string str);
	string read_input(string msg);
	void Add();
	void Search();
	void PrintCompleteContactInfo(Contact contact);
public:
	void Start();
};

#endif