#pragma once
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl

class AForm;

class Bureaucrat
{
	const string name;
	int grade;
	Bureaucrat();
	void CheckGrade(int change);
	Bureaucrat& operator=(const Bureaucrat& obj);
public:
	Bureaucrat(const string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	int getGreade() const;
	string getName() const;
	void increase();
	void decrease();
	void signForm(AForm& f);
	void executeForm(AForm const & form) const ;
	class GradeTooHighException : public std::exception 
	{
	public:
			GradeTooHighException();
			const char *what() const throw() ;
	};
	class GradeTooLowException : public std::exception 
	{
	public:
		GradeTooLowException();
		const char *what() const throw() ;
	};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj);