#include "test.hpp"

int main(int argc, char const *argv[])
{
	Vector v1;
	v1.x = 10;
	v1.y = 20;
	v1.z = 100;

	ClsVector v2;
	v2.x = 10;
	v2.y = 20;
	v2.z = 100;

	cout << "struct vector: " << v1.x << "," << v1.y << "," << v1.z << endl;
	cout << "class vector: " << v2.x << "," << v2.y << "," << v2.z << endl;


	
	return 0;
}
