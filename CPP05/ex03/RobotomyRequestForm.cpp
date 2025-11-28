#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm
(const string& target): AForm("RobotomyRequest", 72, 45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm
(const RobotomyRequestForm& obj):
AForm(obj.getName(), 145, 137)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	(void)obj;
	return *this;
}

void RobotomyRequestForm::exeForm()const
{
	srand(time(0)); 
	int randomNumber = rand();
	if (randomNumber % 2)
		cout << target << " has been robotomized successfull\n";
	else
		cout << "robotomy "<< target <<" failed\n";
}
