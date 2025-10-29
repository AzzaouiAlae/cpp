#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

#define cout std::cout
#define string std::string

class Contact 
{
	string _firstName;
	string _lastName;
	string _nickName;
	string _phoneNumber;
	string _darkestSecret;
public:
	string FirstName();
	void SetFirstName(string firstName);

	string LastName();
	void SetLastName(string lastName);

	string NickName();
	void SetNickName(string nickName);

	string PhoneNumber();
	void SetPhoneNumber(string phoneNumber);

	string DarkestSecret();
	void SetDarkestSecret(string darkestSecret);

	Contact (string firstName, string lastName, string nickName, 
			string phoneNumber, string darkestSecret);
			
	Contact();
};

#endif