#pragma once
#include "Bureaucrat.hpp"

class AForm {
	const string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
	AForm();
	AForm& operator=(const AForm& obj);
protected:
	void CheckGrade(int change);
	void CheckExecute(Bureaucrat const & executor) const;
	virtual void exeForm() const = 0;
public:
	AForm(const string& AFormName, int SignGrade, int ExecuteGrade);
	virtual ~AForm();
	AForm(const AForm& obj);
	string getName() const;
	bool IsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(Bureaucrat& b);
	void execute(Bureaucrat const & executor) const;
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
	class NotSignedException : public std::exception 
	{
	public:
		NotSignedException();
		const char *what() const throw() ;
	};
};

std::ostream& operator<<(std::ostream& o, AForm& obj);
