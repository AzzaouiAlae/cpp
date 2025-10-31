#include "Harl.hpp"

int main()
{
	Harl complain;

	complain.complain("DEBUG");
	complain.complain("INFO");
	complain.complain("WARNING");
	complain.complain("ERROR");
	complain.complain("aaa");
	return 0;
}
