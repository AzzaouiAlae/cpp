#include "easyfind.hpp"

void print(int& i)
{
	cout << i << ", ";
}

void Test1()
{
	int toFind = 10;
	int Arr[] = {10, 20, 30, 50, 100, 954};
	vector<int> nums;

	for(int i = 0; i < 6; i++)
		nums.push_back(Arr[i]);

	std::for_each(nums.begin(), nums.end(), print);
	try {
		int i = easyfind(nums, toFind);
		cout << "\n" << i << " found\n";
	} catch (std::exception& e) {
		cout << "\n" << toFind << " Not found\n";
	}
}

void Test2()
{
	int toFind = 5;
	int Arr[] = {10, 20, 30, 50, 100, 954};
	vector<int> nums;

	for(int i = 0; i < 6; i++)
		nums.push_back(Arr[i]);

	std::for_each(nums.begin(), nums.end(), print);
	try {
		int i = easyfind(nums, toFind);
		cout << "\n" << i << " found\n";
	} catch (std::exception& e) {
		cout << "\n" << toFind << " Not found\n";
	}
}

void Test3()
{
	int toFind = 954;
	int Arr[] = {10, 20, 30, 50, 100, 954};
	vector<int> nums;

	for(int i = 0; i < 6; i++)
		nums.push_back(Arr[i]);

	std::for_each(nums.begin(), nums.end(), print);
	try {
		int i = easyfind(nums, toFind);
		cout << "\n" << i << " found\n";
	} catch (std::exception& e) {
		cout << "\n" << toFind << " Not found\n";
	}
}

int main()
{
	cout << "Test 1: \n";
	Test1();
	cout << "\nTest 2: \n";
	Test2();
	cout << "\nTest 3: \n";
	Test3();

	return 0;
}
