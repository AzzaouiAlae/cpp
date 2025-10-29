#include "PhoneBook.hpp"

void PhoneBook::Add(Contact contact)
{
	_contacts[_currIndex % 8] = contact;
	_currIndex++;
}

int PhoneBook::GetIndex()
{
	return _currIndex;
}
Contact PhoneBook::GetContact(int i) 
{
	return _contacts[i];
}

bool PhoneBook::IsExists(string index) 
{
	if (index.size() > 1)
		return false;
	if (!isdigit(index[0]))
		return false;
	if (index[0] > '0' + _currIndex - 1)
		return false;
	if (index[0] > '0' + 7)
		return false;
	return true;
}

PhoneBook::PhoneBook()
{
	_currIndex = 0;
}
