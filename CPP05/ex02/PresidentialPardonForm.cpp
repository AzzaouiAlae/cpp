#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm
(const string& target):AForm("PresidentialPardon", 25, 5), target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm
(const PresidentialPardonForm& obj):
AForm(obj.getName(), 25, 5)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	(void)obj;
	return *this;
}

void PresidentialPardonForm::exeForm() const
{
	cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
