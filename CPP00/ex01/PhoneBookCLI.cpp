#include "PhoneBookCLI.hpp"

void PhoneBookCLI::Start()
{
	string option;

	while (true) {
		DrawOptionScreen();
		do {
			option = read_input("$ ");
		} while (option != "ADD" && option != "SEARCH" && option != "EXIT");
		if (option == "ADD")
			Add();
		else if (option == "SEARCH")
			Search();
		else if (option == "EXIT")
			break;
	}
}

void PhoneBookCLI::DrawOptionScreen()
{
	system("clear");
	cout << "  Awesome PhoneBook  \n";
	cout << "----------------------\n";
	cout << "- ADD\n";
	cout << "- SEARCH\n";
	cout << "- EXIT\n";
	cout << "----------------------\n";
}

string PhoneBookCLI::read_input(string msg)
{
	string input;

	do {
		cout << msg;
		if (!std::getline(cin, input))
		{
			if (cin.eof()) 
			{
    			cin.clear();
    			freopen("/dev/tty", "r", stdin);
				cout << endl;
				return "";
			}
		}
	} while (input == "");
	return input;
}

void PhoneBookCLI::Add()
{
	Contact contact;
	
	DrawAddScreen();
	contact.SetFirstName(read_input("Enter your Firstname: "));
	if (contact.FirstName() == "")
		return;
	contact.SetLastName(read_input("Enter your Lastname: "));
	if (contact.LastName() == "")
		return;
	contact.SetNickName (read_input("Enter your Nickname: "));
	if (contact.NickName() == "")
		return;
	contact.SetPhoneNumber(read_input("Enter your Phone number: "));
	if (contact.PhoneNumber() == "")
		return;
	contact.SetDarkestSecret(read_input("Enter your Darkest secret: "));
	if (contact.DarkestSecret() == "")
		return;
	_phoneBook.Add(contact);
}

void PhoneBookCLI::DrawAddScreen()
{
	system("clear");
	cout << "  Awesome PhoneBook  \n";
	cout << "=====================\n";
	cout << "   Add new contact\n";
	cout << "----------------------\n";
}

void PhoneBookCLI::Search()
{
	string index;
	Contact contact;
	
	DrawSearchScreen();
	if (_phoneBook.GetIndex())
	{
		do {
			index = read_input("$ ");
			if (index == "")
				break;
		} while(!_phoneBook.IsExists(index));
		if (index != "")
		{
			contact = _phoneBook.GetContact(index[0] - '0');
			PrintCompleteContactInfo(contact);
		}
	}
	if (index != "")
	{
		cout << "Press enter to return ...";
		std::getline(cin, index);
	}
}

void PhoneBookCLI::DrawSearchScreen()
{
	int size;

	system("clear");
	cout << "------------------------------------------------\n";
	cout << "|              Awesome PhoneBook               |\n";
	cout << "|==============================================|\n";
	cout << "|                   Search                     |\n";
	cout << "|----------------------------------------------|\n";
	cout << "| index | Firstname  | Lastname   | Nickname   |\n";
	cout << "|----------------------------------------------|\n";
	size = _phoneBook.GetIndex() > 8 ? 8 : _phoneBook.GetIndex();
	for(int i = 0; i < size; i++)
		PrintContact(_phoneBook.GetContact(i), i);
	cout << "------------------------------------------------\n";
}

void PhoneBookCLI::PrintContact(Contact contact, int index)
{
	cout << "| " << index << "\t| ";
	PrintSubStr(contact.FirstName());
	PrintSubStr(contact.LastName());
	PrintSubStr(contact.NickName());
	cout << "\n";
}

void PhoneBookCLI::PrintSubStr(string str)
{
	size_t size = str.size();
	if (size > 10)
		cout << str.substr(0, 7) << "... | ";
	else
	{
		cout << str;
		while (size++ < 10)
			cout << " ";
		cout << " | ";
	}
}

void PhoneBookCLI::PrintCompleteContactInfo(Contact contact)
{
	string str;

	cout << "FirstName     : " <<	contact.FirstName() << "\n";
	cout << "LastName      : " <<	contact.LastName() << "\n";
	cout << "NickName      : " <<	contact.NickName() << "\n";
	cout << "Phone number  : " <<	contact.PhoneNumber() << "\n";
	cout << "Darkest secret: " <<	contact.DarkestSecret() << "\n";
}
