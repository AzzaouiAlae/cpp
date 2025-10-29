#ifndef MINE_H
#define MINE_H

#include "theirs.hpp"
#include <iostream>

#define cout std::cout
#define string std::string
#define endl std::endl

namespace Example {
	extern const int test;
	extern const int test2;
}
namespace foo {
	void func();
	void funcfunc();
}

namespace Test {
	void call(int i);
	class SomeClass {
		int SomeData;
		public:
		int GetSomeData();
		void SetSomeData(int data);
	};
	void call_too(SomeClass &data);
}

namespace N {
	struct X
	{
		int a;
	};
	void foo(X data);
	void qux(X data);
}



#endif