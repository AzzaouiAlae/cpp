#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	typedef AForm *(Intern::*func)(const string& target);
	std::pair<string, func> p[3];
	AForm *createShrubbery(const string& target);
	AForm *createRobotomyRequest(const string& target);
	AForm *createPresidentialPardon(const string& target);
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);
	void InitPair(const string &name, func f, int i);
	void InitPairs();
public:
	Intern();
	~Intern();
	AForm *makeForm(const string& formName, const string& target);
};
