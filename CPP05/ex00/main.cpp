#include "Bureaucrat.hpp"

void Test1()
{
	try
	{
	/* do some stuff with bureaucrats */
	}
	catch (std::exception & e)
	{
	/* handle exception */
	}
}

void Test2()
{
	try {
		Bureaucrat var1("Someone", 0);
	}
	catch (std::exception & e) {
		cout << e.what() << '\n';
	}
}

void Test3()
{
	try {
		Bureaucrat var1("Someone", 151);
	}
	catch (std::exception & e) {
		cout << e.what() << '\n';
	}
}

void Test4()
{
	try {
		Bureaucrat var1("Someone", 1);
		cout << var1;
	}
	catch (std::exception & e) {
		cout << e.what() << '\n';
	}
}

void Test5()
{
	try {
		Bureaucrat var1("Someone", 9);
		for(int i = 0; i < 10; i++)
		{
			cout << var1;
			var1.increase();
		}
	}
	catch (std::exception & e) {
		cout << e.what() << '\n';
	}
}

void Test6()
{
	try {
		Bureaucrat var1("Someone", 141);
		for(int i = 0; i < 10; i++)
		{
			cout << var1;
			var1.decrease();
		}
	}
	catch (std::exception & e) {
		cout << e.what() << '\n';
	}
}

int main()
{
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
}
