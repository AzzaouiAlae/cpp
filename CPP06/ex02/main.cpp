#include "Type.hpp"

int main()
{
	Base *b = Type::generate();

	Type::identify(b);
	Type::identify(*b);
	delete b;
	cout << '\n';


	A a = A();
	Base &b2 = a;
	Type::identify(&b2);

	
	
	return 0;
}
