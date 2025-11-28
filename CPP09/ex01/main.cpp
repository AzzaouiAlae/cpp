#include "RPN.hpp"

int main(int c, char *v[])
{
	if (c != 2)
	{
		cout << "Error: invalid argument\n" << "./RPN \"1 1 +\"" << endl;
		return 1; 
	}
	try {
		RPN rpn(v[1]);
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
