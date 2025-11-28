#include "iter.hpp"

void print(const int &i)
{
	cout << i << " ";
}

void AddOne(int &i)
{
	i++;
}

int main()
{
	int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80,90,100};
	iter(arr, 11, print);
	cout << '\n';
	iter(arr, 11, AddOne);
	iter(arr, 11, print);
	cout << '\n';
	return 0;
}
