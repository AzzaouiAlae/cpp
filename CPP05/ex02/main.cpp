#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void Test1()
{
	try {
		ShrubberyCreationForm a("Form1");
		Bureaucrat b("Someone", 5);
		a.beSigned(b);
		a.execute(b);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test2()
{
	try {
		ShrubberyCreationForm a("Form1");
		Bureaucrat b("Someone", 145);
		a.beSigned(b);
		a.execute(b);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test3()
{
	try {
		ShrubberyCreationForm a("Form1");
		Bureaucrat b("Someone", 150);
		a.beSigned(b);
		a.execute(b);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test4()
{
	try {
		RobotomyRequestForm a("Form1");
		Bureaucrat b("Someone", 150);
		a.beSigned(b);
		a.execute(b);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test5()
{
	try {
		RobotomyRequestForm a("Form1");
		Bureaucrat b("Someone", 1);
		a.beSigned(b);
		a.execute(b);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test6()
{
	try {
		ShrubberyCreationForm s("home");
		Bureaucrat b("Someone", 1);
		b.signForm(s);
		b.executeForm(s);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test7()
{
	try {
		RobotomyRequestForm r("Compilation");
		Bureaucrat b("Someone", 1);
		b.signForm(r);
		b.executeForm(r);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test8()
{
	try {
		PresidentialPardonForm r("1337Student");
		Bureaucrat b("Someone", 1);
		b.signForm(r);
		b.executeForm(r);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

void Test9()
{
	try {
		PresidentialPardonForm r("1337Student");
		Bureaucrat b("Someone", 6);
		b.signForm(r);
		b.executeForm(r);
	} catch (std::exception &e) {
		cout << e.what() << '\n';
	}
}

int main()
{
	Test1();
	cout << '\n';
	Test2();
	cout << '\n';
	Test3();
	cout << '\n';
	Test4();
	cout << '\n';
	Test5();
	cout << '\n';
	Test6();
	cout << '\n';
	Test7();
	cout << '\n';
	Test8();
	cout << '\n';
	Test9();
}
