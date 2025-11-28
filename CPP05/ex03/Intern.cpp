#include "Intern.hpp"
#include <map>

Intern::Intern()
{
	InitPairs();
}

Intern::~Intern()
{}

void Intern::InitPair(const string &name, func f, int i)
{
	p[i].first = name;
	p[i].second = f;
}

void Intern::InitPairs()
{
	InitPair("shrubbery", &Intern::createShrubbery, 0);
	InitPair("robotomy reques", &Intern::createRobotomyRequest, 1);
	InitPair("presidential pardon", &Intern::createPresidentialPardon, 2);
}

AForm* Intern::createShrubbery(const string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequest(const string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const string& formName, const string& target)
{
	std::map<string, func> a;
	a["debug"] = &createPresidentialPardon;
	cout << a[formName];

	for(int i = 0; i < 3; i++) {
		if (formName == p[i].first)
		{
			Intern &cur_obj = *this;
			func f = p[i].second;
			AForm *obj = (cur_obj.*f)(target);
			cout << "Intern creates " << formName << endl;
			return obj;
		}
	}
	cout << "Error: " << formName << " Form not exist" << endl;
	return NULL;
}
