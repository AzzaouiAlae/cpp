#pragma once
#include <iostream>

#define string std::string
#define cout std::cout
#define endl std::endl

class Bureaucrat
{
	const string name;
	int grade;
	Bureaucrat();
	void CheckGrade(int change);
	Bureaucrat& operator=(const Bureaucrat& obj);
public:
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat(const string& name, int grade);
	~Bureaucrat();
	int getGreade();
	string getName() const;
	void increase();
	void decrease();
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