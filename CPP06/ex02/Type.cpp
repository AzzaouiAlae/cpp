#include "Type.hpp"

Type::~Type(){}

Type& Type::operator=(const Type& obj) 
{
	(void)obj; 
	return *this;
}

Base * Type::generate(void)
{
	srand(time(0));
	int randomNumber = rand();

	if (randomNumber % 3 == 0)
	{
		cout << "object A has generated\n";
		return new A();
	}
	if (randomNumber % 2 == 0)
	{
		cout << "object B has generated\n";
		return new B();
	}
	cout << "object C has generated\n";
	return new C();
}

void Type::identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		cout << "Type of object is A\n";
		return;
	}

	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		cout << "Type of object is B\n";
		return;
	}

	C* c = dynamic_cast<C *>(p);
	if (c)
	{
		cout << "Type of object is C\n";
		return;
	}

	cout << "Type of object is not A, B or C\n";
}

void Type::identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		cout << "Type of object is A\n";
		return;
	} 
	catch(std::exception& e) 
	{}
	
	try {
		dynamic_cast<B&>(p);
		cout << "Type of object is B\n";
		return;
	} 
	catch (std::exception& e) 
	{}

	try {
		dynamic_cast<C&>(p);
		cout << "Type of object is C\n";
	} 
	catch (std::exception& e) {
		cout << "Type of object is not A, B or C\n";
	}
}
