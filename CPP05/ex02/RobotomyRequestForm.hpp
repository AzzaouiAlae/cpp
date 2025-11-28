#pragma once
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	string target;
	RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm& obj);
	void exeForm() const;
public:
	RobotomyRequestForm(const string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& obj);
};
