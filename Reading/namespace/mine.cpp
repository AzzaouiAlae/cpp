#include "mine.hpp"

void func()
{
	cout << "hello from fun" << endl;
}

void foo::func()
{
	cout << "hello from foo::fun" << endl;
}

void foo::funcfunc()
{
	cout << "hello from foo::funcfunc I use ::func\n{" << endl << "\t";
	::func();
	cout << "}\n";
}

const int Example::test = 5;
const int Example::test2 = Example::test + 12;

int Test::SomeClass::GetSomeData()
{
	return SomeData;
}

void Test::call(int i){
	cout << "hello from Test::call\n" << "the data is: " << i << endl;
}

void Test::call_too(SomeClass &data){
	cout << "hello from call_too\n" << "the data is: " << data.GetSomeData() << endl;
}

void Test::SomeClass::SetSomeData(int data)
{
	SomeData = data;
}

void N::foo(X data) {
	cout << data.a << endl;
}
void N::qux(X data) {
	cout << data.a << endl;
}

struct C {
	void foo() {

	}
	void func() {
		N::foo(N::X{});
	}
};

void func_() {
	// extern void foo();
	// foo(N::X {});
}

int qux;

void _func() {
	// qux(N::X {});
}

namespace Test {
	int SomeOtherData = 30;
}

int main(int argc, char const *argv[])
{
	char str[] = "hello world!";
	for (int i = 0; str[i]; i++)
		str[i] = mylib::ft_to_uppercase(str[i]);
	cout << str << '\n' << geo::circumf(h) << '\n';
	using namespace geo;
	cout << circumf(h) << '\n';
	string a = "Hello";
	cout << a << '\n';

	cout << "\n\n";
	cout << Example::test << '\n';
	cout << Example::test2 << '\n';

	cout << "\n\n";
	func();
	foo::func();
	foo::funcfunc();


	cout << "\n\n";
	Test::call(5); // it must use Test::
	Test::SomeClass data; 
	data.SetSomeData(100);
	call_too(data); //it work without Test:: because of the parameter is part of the namesapce

	cout << "\n\n";;
	cout << Test::SomeOtherData << "\n";

	

	return 0;
}
