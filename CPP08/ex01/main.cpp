#include "Span.hpp"
#include <ctime>

void print(int i)
{
	cout << i << ", ";
}

void Test1()
{
	cout << "Test 1 | addRange with (array of int)\n";
	int arr[] = {10, 20, 30, 40};
	
	Span s(15);
	s.addRange(arr, 4);

	s.forEach(print);

	cout << '\n';
}

void Test2()
{
	cout << "\nTest 2 | Add numbers, forEach, shortestSpan, longestSpan\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.forEach(print);
	cout << '\n';

	cout << sp.shortestSpan() << endl;
	cout << sp.longestSpan() << endl;
}

void Test3()
{
	cout << "\nTest 3 | Add too many numbers to test exception\n";
	Span sp = Span(2);
	sp.addNumber(6);
	sp.addNumber(7);

	try {
		sp.addNumber(8);
		cout << "No exception throw, test fail\n";
	} catch (std::exception& e) {
		cout << "exception throw as expected\n";
	}
}

void Test4()
{
	cout << "\nTest 4 | add range with vector\n";
	int arr[] = {10, 20, 30, 40};
	vector<int> nums;
	cout << "vector nums: ";
	for(size_t i = 0; i < 4; i++)
	{
		cout << arr[i] << ", ";
		nums.push_back(arr[i]);
	}
	cout << '\n';
	Span sp = Span(4);
	sp.addRange(nums);
	cout << "Span nums  : ";
	sp.forEach(print);
	cout << '\n';
}

void Test5()
{
	cout << "\nTest 5 | add range with vector iterator begin + 1, end - 1\n";
	int arr[] = {10, 20, 30, 40};
	vector<int> nums;
	cout << "vector nums: ";
	for(size_t i = 0; i < 4; i++)
	{
		cout << arr[i] << ", ";
		nums.push_back(arr[i]);
	}
	cout << '\n';
	Span sp = Span(4);
	sp.addRange(nums.begin() + 1, nums.end() - 1);
	cout << "Span nums  : ";
	sp.forEach(print);
	cout << '\n';
}

void Test6()
{
	cout << "\nTest 6 | shortestSpan with 1 element\n";
	Span sp = Span(5);
	sp.addNumber(6);

	sp.forEach(print);
	cout << '\n';
	try {
		cout << sp.shortestSpan() << endl;
		cout << "No exception throw, test fail\n";
	} catch (std::exception& e) {
		cout << "exception throw as expected\n";
	}
}

void Test7()
{
	cout << "\nTest 7 | longestSpan with 1 element\n";
	Span sp = Span(5);
	sp.addNumber(6);

	sp.forEach(print);
	cout << '\n';
	try {
		cout << sp.longestSpan() << endl;
		cout << "No exception throw, test fail\n";
	} catch (std::exception& e) {
		cout << "exception throw as expected\n";
	}
}

void Test8()
{
	cout << "\nTest 8 | copy constractor\n";
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	Span sp2 = sp1;

	cout << "sp1: ";
	sp1.forEach(print);
	cout << "\nsp2: ";
	sp2.forEach(print);
	sp1[0] = 15;
	cout << "\nchange sp1: ";
	sp1.forEach(print);
	sp2[0] = 50;
	cout << "\nchange sp2: ";
	sp2.forEach(print);
	cout << '\n';
}

void Test9()
{
	cout << "\nTest 9 | = operator\n";
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	Span sp2(1);
	sp2 = sp1;

	cout << "sp1: ";
	sp1.forEach(print);
	cout << "\nsp2: ";
	sp2.forEach(print);
	sp1[0] = 15;
	cout << "\nchange sp1: ";
	sp1.forEach(print);
	sp2[0] = 50;
	cout << "\nchange sp2: ";
	sp2.forEach(print);
	cout << '\n';
}

void Test10()
{
	cout << "\nTest 10 | [] operator out of range\n";
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	try {
		sp1[10] = 15;
		cout << "No exception throw, test fail\n";
	} catch (std::exception& e) {
		cout << "exception throw as expected\n";
	}
}

void Test11()
{
	cout << "\nTest 11 | 20,000 item\n";
	std::srand(std::time(NULL));

    vector<int> v;
    v.reserve(20000);

    // Fill the vector with 20,000 random ints
    for (int i = 0; i < 20000; i++) {
        int r = std::rand() * (i % 3 ? -1 : 1);
        v.push_back(r);
    }

    // You cannot compute span with < 2 numbers
    if (v.size() < 2) {
        cout << "Not enough numbers\n";
        return ;
    }

    // Highest span = max - min
    int minVal = *std::min_element(v.begin(), v.end());
    int maxVal = *std::max_element(v.begin(), v.end());
    long highestSpan = labs((long)maxVal - (long)minVal);

    // Lowest span (sort then find smallest difference)
    std::sort(v.begin(), v.end());

    long lowestSpan = labs((long)v[1] - (long)v[0]);
    for (size_t i = 1; i < v.size() - 1; i++) {
        long diff = labs((long)v[i + 1] - (long)v[i]);
        if (diff < lowestSpan)
            lowestSpan = diff;
    }
	Span sp = Span(20000);
	sp.addRange(v);

    cout << "vector Lowest span:  " << lowestSpan << endl;
	cout << "span Lowest span  :  " << sp.shortestSpan() << endl;
    cout << "vector Highest span: " << highestSpan << endl;
	cout << "span Highest span  : " << sp.longestSpan() << endl;
}

void Test12() 
{
	cout << "\nTest 11 | overflow test\n";
	Span sp = Span(2);
	sp.addNumber(2147483647);
	sp.addNumber(-2147483648);
	cout << sp.longestSpan() << endl;
	cout << sp.shortestSpan() << endl;

}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();

	return 0;
}
