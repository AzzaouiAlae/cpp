#include "MutantStack.hpp"
#include <list>

void Test1()
{
	cout << "\nTest 1\n";
	MutantStack<int> a;
	a.push(15);
	a.push(20);
	a.size();

	for (MutantStack<int>::iterator it = a.begin(); it < a.end(); it++)
		cout << *it << '\n';
}

void Test2()
{
	cout << "\nTest 2\n";
	MutantStack<int> a;
	a.push(15);
	a.push(20);
	a.size();

	MutantStack<int>::iterator it = a.begin();
	while (it != a.end())
	{
		int i = *it++;
		cout << i << '\n';
	}
}

void Test3()
{
	cout << "\nTest 3\n";
	MutantStack<int> a;
	a.push(15);
	a.push(20);
	a.size();

	MutantStack<int>::iterator it = a.begin() - 1;
	while (it + 1 != a.end())
	{
		int i = *(++it);
		cout << i << '\n';
	}
}

void Test4()
{
	cout << "\nTest 4\nMutantStack\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	cout << mstack.top() << endl;
	mstack.pop();
	cout << mstack.size() << endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		cout << *it << endl;
		++it;
	}
	std::stack<int> s(mstack);

	cout << "\nTest 4\nlist\n"; 
	std::list<int> l;
	l.push_front(5); // 5
	l.push_front(17); // 17 5
	cout << l.front() << endl; // print 17
	l.pop_front(); // 5
	cout << l.size() << endl; // print 1
	l.push_front(3); // 5
	l.push_front(5);
	l.push_front(737);
	//[...]
	l.push_front(0);
	std::list<int>::iterator it2 = l.begin();
	std::list<int>::iterator ite2 = l.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		cout << *it2 << endl;
		++it2;
	}
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}
