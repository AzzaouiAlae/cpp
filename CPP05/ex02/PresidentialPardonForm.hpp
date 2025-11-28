#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	string target;
	PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm& obj);
	void exeForm() const;
public:
	PresidentialPardonForm(const string& target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& obj);
};
