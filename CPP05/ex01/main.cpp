#include "Form.hpp"
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

void Test7()
{
	try {
		Form obj1("Form1", 0, 10);
	} catch (std::exception& e) {
		cout << e.what() << '\n';
	}

}

void Test8()
{
	try {
		Form obj1("Form1", 10, 0);
	} catch (std::exception& e) {
		cout << e.what() << '\n';
	}
}

void Test9()
{
	try {
		Form obj1("Form1", 100, 151);
	} catch (std::exception& e) {
		cout << e.what() << '\n';
	}
}

void Test10()
{
	try {
		Form obj1("Form1", 151, 1);
	} catch (std::exception& e) {
		cout << e.what() << '\n';
	}
}

void Test11()
{
	try {
		Form obj1("Form1", 150, 1);
		cout << obj1 << endl;
	} catch (std::exception& e) {
		cout << e.what() << '\n';
	}
}

void Test12()
{
	try {
		Form obj1("Form1", 90, 1);
		Bureaucrat b("SomeOne", 100);
		b.signForm(obj1);
		cout << obj1;
	} catch (std::exception& e) {
		cout << "Error: " << e.what() << '\n';
	}
}

void Test13()
{
	try {
		Form obj1("Form1",1, 1);
		Bureaucrat b("SomeOne", 100);
		b.signForm(obj1);
		cout << obj1;
	} catch (std::exception& e) {
		cout << e.what() << '\n';
	}
}

int main()
{
	Test2();
	Test3();
	Test4();
	// Test5();
	// Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();
	Test13();
}
