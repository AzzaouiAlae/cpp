#include "AForm.hpp"

AForm::AForm(const string& AFormName, int signGrade, int executeGrade):
name(AFormName), signGrade(signGrade), executeGrade(executeGrade)
{
	CheckGrade(0);
	isSigned = false;
}

void AForm::CheckGrade(int change)
{
	if (signGrade + change > 150 || executeGrade + change > 150)
		throw GradeTooLowException("Try to make grade lower then 150");
	if (signGrade + change < 1 || executeGrade + change < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{}

AForm::AForm(const AForm& obj):
name(obj.name), signGrade(obj.signGrade),
executeGrade(obj.executeGrade)
{}

AForm& AForm::operator=(const AForm& obj) 
{
	(void)obj;
	return *this;
}

string AForm::getName() const
{
	return name;
}

bool AForm::IsSigned() const
{
	return isSigned;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}

void AForm::beSigned(Bureaucrat& b)
{
	if ( b.getGreade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException("Try to sign a form with too low greade");
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Try to make grade greater then 1";
}

const char *AForm::GradeTooLowException::what() const throw(){
	return msg.c_str();
}

AForm::GradeTooLowException::
GradeTooLowException(const string& msg): msg(msg) {
}

AForm::GradeTooHighException::
GradeTooHighException() {
}

void AForm::CheckExecute(Bureaucrat const & executor) const
{
	if (isSigned == false)
		throw NotSignedException();
	if (executor.getGreade() > executeGrade)
		throw GradeTooLowException("Try to execute a Form with too low bureaucrat greade");
}

std::ostream& operator<<(std::ostream& o, AForm& obj)
{
	o << obj.getName() << " = SignGrade: " << obj.getSignGrade() << 
		" | ExecuteGrade: " << obj.getExecuteGrade() <<
		" | isSigned: " << (obj.IsSigned() ? "True" : "false") <<"\n";
	return o;
}

AForm::NotSignedException::NotSignedException()
{}

const char* AForm::NotSignedException::what() const throw(){
	return "Try to execute unsigned Form";
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
}

void AForm::execute(Bureaucrat const & executor) const{
	CheckExecute(executor);
	exeForm();
}