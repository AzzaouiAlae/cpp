#pragma once
#include "AForm.hpp"
#include <iostream>
#include <bits/stdc++.h>

class ShrubberyCreationForm : public AForm
{
	string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
	void exeForm() const;
public:
	ShrubberyCreationForm(const string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
};
