#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): grade(150)
{}

Bureaucrat::Bureaucrat(const string& name, int grade): 
	name(name), grade(grade)
{
	CheckGrade(0);
}

void Bureaucrat::CheckGrade(int change)
{
	if (grade + change > 150)
		throw GradeTooLowException
		();
	if (grade + change < 1)
		throw GradeTooHighException();
}

void Bureaucrat::increase()
{
	CheckGrade(-1);
	grade--;
}

void Bureaucrat::decrease()
{
	CheckGrade(+1);
	grade++;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): name(obj.name), grade(obj.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	(void)obj;
	return *this;
}

int Bureaucrat::getGreade()
{
	return grade;
}

string Bureaucrat::getName() const
{
	return name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Try to make grade greater then 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Try to make grade lower then 150";
}

Bureaucrat::GradeTooLowException::
GradeTooLowException() {
}

Bureaucrat::GradeTooHighException::
GradeTooHighException() {
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGreade() << "\n";
	return o;
}

void Bureaucrat::signForm(Form& f)
{
	try {
		f.beSigned(*this);
		cout << name << " signed " << f.getName() << endl;
	} catch (std::exception& e) {
		cout << getName() + " couldn't sign " + f.getName() + " Because grade is too low\n";
		// throw;
	}
}