#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <cstdio>

#define cin std::cin

class PhoneBook {
	Contact _contacts[8];
	int _currIndex;
public:
	bool IsExists(string index);
	Contact GetContact(int i);
	int GetIndex();
	void Add(Contact contact);
	PhoneBook();
};

#endif