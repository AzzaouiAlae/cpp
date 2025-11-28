#include "BitcoinExchange.hpp"

int main(int c, char *v[])
{
	if (c != 2)
	{
		cout <<"Error: invalid argument\n" << "./btc fileName" << endl;
		return 1; 
	}
	try {
		BitcoinExchange exchange;
		// exchange.PrintDatabase();
		exchange.Change(v[1]);
	} catch (std::exception& e) {
		cout << e.what() << "\n";
		return 1;
	}
	return 0;
}
