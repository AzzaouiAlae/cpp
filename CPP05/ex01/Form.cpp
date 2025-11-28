#include "Form.hpp"

Form::Form(const string& formName, int signGrade, int executeGrade):
name(formName), signGrade(signGrade), executeGrade(executeGrade)
{
	CheckGrade(0);
	isSigned = false;
}

void Form::CheckGrade(int change)
{
	if (signGrade + change > 150 || executeGrade + change > 150)
		throw GradeTooLowException("Try to make grade lower then 150");
	if (signGrade + change < 1 || executeGrade + change < 1)
		throw GradeTooHighException();
}

Form::~Form()
{}

Form::Form(const Form& obj):
name(obj.name), signGrade(obj.signGrade),
executeGrade(obj.executeGrade)
{}

Form& Form::operator=(const Form& obj) 
{
	(void)obj;
	return *this;
}

string Form::getName()
{
	return name;
}

bool Form::IsSigned()
{
	return isSigned;
}

int Form::getSignGrade()
{
	return signGrade;
}

int Form::getExecuteGrade()
{
	return executeGrade;
}

void Form::beSigned(Bureaucrat& b)
{
	if ( b.getGreade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException("Try to sign a form with too low greade");
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Try to make grade greater then 1";
}

const char *Form::GradeTooLowException::what() const throw(){
	return msg.c_str();
}

Form::GradeTooLowException::
GradeTooLowException(const string& msg): msg(msg) {
}

Form::GradeTooHighException::
GradeTooHighException() {
}

std::ostream& operator<<(std::ostream& o, Form& obj)
{
	o << obj.getName() << " = SignGrade: " << obj.getSignGrade() << 
		" | ExecuteGrade: " << obj.getExecuteGrade() <<
		" | isSigned: " << (obj.IsSigned() ? "True" : "false") <<"\n";
	return o;
}

Form::GradeTooLowException::~GradeTooLowException() throw(){
}