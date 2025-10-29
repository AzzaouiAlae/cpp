#include "Contact.hpp"

string Contact::FirstName() {
	return _firstName;
}
void Contact::SetFirstName(string firstName) {
	_firstName = firstName;
}

string Contact::LastName() {
	return _lastName;
}
void Contact::SetLastName(string lastName){
	_lastName = lastName;
}

string Contact::NickName() {
	return _nickName;
}
void Contact::SetNickName(string nickName) {
	_nickName = nickName;
}

string Contact::PhoneNumber() {
	return _phoneNumber;
}
void Contact::SetPhoneNumber(string phoneNumber) {
	_phoneNumber = phoneNumber;
}

string Contact::DarkestSecret() {
	return _darkestSecret;
}
void Contact::SetDarkestSecret(string darkestSecret) {
	_darkestSecret = darkestSecret;
}

Contact::Contact (string firstName, string lastName, string nickName, 
	string phoneNumber, string darkestSecret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}
			
Contact::Contact() {

}