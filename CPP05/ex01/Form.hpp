#pragma once
#include "Bureaucrat.hpp"

class Form {
	const string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
	Form();
	void CheckGrade(int change);
	Form& operator=(const Form& obj);
public:
	Form(const string& formName, int SignGrade, int ExecuteGrade);
	~Form();
	Form(const Form& obj);
	string getName();
	bool IsSigned();
	int getSignGrade();
	int getExecuteGrade();
	void beSigned(Bureaucrat& b);
	class GradeTooHighException : public std::exception 
	{
	public:
		GradeTooHighException();
		const char *what() const throw() ;
	};
	class GradeTooLowException : public std::exception 
	{
		const string msg;
	public:
		~GradeTooLowException() throw();
		GradeTooLowException(const string& msg);
		const char *what() const throw() ;
	};
};

std::ostream& operator<<(std::ostream& o, Form& obj);
