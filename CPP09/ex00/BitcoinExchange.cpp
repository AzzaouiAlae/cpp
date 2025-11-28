#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	InitDatabase();
}

void BitcoinExchange::InitDatabase()
{
	int idx = 0;
	long num;

	string data, key, value;
	string line;
	ReadFile(data, "Initialization of database failed", "data.csv");
	line = NextLine(data, idx);
	if (line != "date,exchange_rate")
		throw BitconinException("Error: invalid database file format");
	while (line != "")
	{
		try {
			ParseLine(line, key, value, ",");
			CheckDate(key);
			num = ParseNumber(value);
			database[key] = num;
			line = NextLine(data, idx);
		} catch (std::exception& e) {
			(void)e;
			line = NextLine(data, idx);
		}
	}
}

void BitcoinExchange::Change(string file)
{
	int idx = 0;
	long num;
	string data, key, value, line;
	
	ReadFile(data, "Reading input file failed", file);
	line = NextLine(data, idx);
	if (line != "date | value")
		throw BitconinException("Error: invalid input file format");
	line = NextLine(data, idx);
	while (line != "")
	{
		try {
			ParseLine(line, key, value, " | ");
			CheckDate(key);
			num = ParseNumber(value);
			if (num > 1000 * pow(10, FRACTION_SIZE))
				throw BitconinException("Error: too large number");
			PrintItem(key, num);
			line = NextLine(data, idx);
		} catch (std::exception& e) {
			string s = e.what();
			PrintItem(s, -1);
			line = NextLine(data, idx);
		}
	}
}

void BitcoinExchange::ReadFile(string& data, const string& err, const string& file)
{
	std::ifstream in(file.c_str());
	if (!in.is_open())
		throw BitconinException(err);

	in.seekg(0, std::ios::end);
	data.reserve(in.tellg());
	in.seekg(0, std::ios::beg);
	data.assign(std::istreambuf_iterator<char>(in),
				std::istreambuf_iterator<char>());
}

string BitcoinExchange::NextLine(string& s, int& start)
{
	size_t i = s.find('\n', start);
	if (i == string::npos)
		return "";
	string l = s.substr(start, i - start);
	start = i + 1;
	return l;
}

void BitcoinExchange::ParseLine(string& line, string& key, string& value, const string& sep)
{
	size_t i = line.find(sep);
	std::stringstream err;

	if (i == string::npos)
	{
		err << "Error: bad input => " << line;
		throw  BitconinException(err.str());
	}
	key = line.substr(0, i);
	value = line.substr(i + sep.length());
}

void BitcoinExchange::CheckDate(string& date)
{
	std::stringstream err;
	string dt = date;
	int year, month, day;

	try {
		year = std::atoi(dt.c_str());
		dt = dt.substr(dt.find('-') + 1);
		month = std::atoi(dt.c_str());
		dt = dt.substr(dt.find('-') + 1);
		day = std::atoi(dt.c_str());
		if (isValidDate(year, month, day))
			return;
	} catch (std::exception& e) {
		(void)e;
	}
	err << "Error: bad input => " << date;
	throw  BitconinException(err.str());
}

bool BitcoinExchange::isValidDate(int year, int month, int day)
{
    if (year < 2009 || month < 1 || month > 12 
		|| day < 1 || day > 31) 
        return false;
    
    int daysInMonth[] = { 
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
	};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	if (day > daysInMonth[month])
        return false;
	return true;
}

long BitcoinExchange::ParseNumber(string& completeNum)
{
	char *end;
	int dotIndex;
	string fraction;
	long num;
	
	dotIndex = completeNum.find(".");
	fraction = completeNum.substr(dotIndex + 1);
	num = std::strtol(completeNum.c_str(), &end, 10) * pow(10, FRACTION_SIZE);
	throwErrors(num, end, completeNum);
	if (dotIndex != -1)
	{
		while (fraction.length() < FRACTION_SIZE)
			fraction += "0";
		if (fraction.length() > FRACTION_SIZE)
			fraction = fraction.substr(0, FRACTION_SIZE);
		num += std::strtol(fraction.c_str(), &end, 10);
		if (fraction != "")
			throwErrors(num, end, completeNum);
	}
	return num;
}

void BitcoinExchange::throwErrors(long& num, char *end, string& completeNum)
{
	std::stringstream err;

	if (errno == ERANGE || num > 2147483647l * pow(10, FRACTION_SIZE))
	{
		err << "Error: too large number."; 
		throw  BitconinException(err.str());
	}
	if (end[0] != 0 && end[0] != '.')
	{
		err << "Error: " << completeNum << " is not a number.";
		throw  BitconinException(err.str());
	}
	if (num < 0)
	{
		err << "Error: " << " not positive number.";
		throw  BitconinException(err.str());
	}
}

void BitcoinExchange::PrintItem(string& key, long value)
{
	std::map<string, long>::iterator db_it;
	string k = key;
	long result;
	int f = pow(10, FRACTION_SIZE);

	if (value == -1)
		cout << key << '\n';
	else
	{
		do {
			db_it = database.find(key);
			key = DecreaseDay(key);
		} while (db_it == database.end());
		if (db_it != database.end())
		{
			result = value * (*db_it).second;
			result /= f;
			cout << k << " => ";
			PrintNumber(value, 2);
			cout << " = ";
			PrintNumber(result, 2);
			cout << endl;
		}
	}
}

string BitcoinExchange::DecreaseDay(string dt)
{
	int year, month, day;
	int daysInMonth[] = { 
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
	};
	std::stringstream str;
	year = std::atoi(dt.c_str());
	dt = dt.substr(dt.find('-') + 1);
	month = std::atoi(dt.c_str());
	dt = dt.substr(dt.find('-') + 1);
	day = std::atoi(dt.c_str());
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	if (day == 1)
	{
		if (month == 1)
		{
			year--;
			month = 12;
			day = 31;
		}
		else
		{
			month--;
			day = daysInMonth[month];
		}
	}
	else
		day--;
	str << year << '-';
	if (month >= 10)
		str << month << '-';
	else
		str << '0' << month << '-';

	if (day >= 10)
		str << day;
	else
		str << '0' << day;
	return str.str();
}

void BitcoinExchange::PrintNumber(long num, int fracDigits)
{
	long f = pow(10, FRACTION_SIZE);
	long itegerNum = num / f;
	cout << itegerNum;
	long fracNum = num % f / pow(10, FRACTION_SIZE - fracDigits);
	if (fracNum)
	{
		if (fracNum < pow(10, fracDigits - 1))
		{
			cout << ".";
			while(fracNum < pow(10, fracDigits - 1))
			{
				cout << "0";
				fracDigits--;
			}
			cout << fracNum;
		}
		else
		{
			int i = 1;
			while(fracNum % (i * 10) == 0)
				i *= 10;
			cout << '.' << fracNum / i;
		}
	}
}

void BitcoinExchange::PrintDatabase()
{
	std::for_each(database.begin(), database.end(), PrintPair);
}

void BitcoinExchange::PrintPair(const std::pair<string, long> item)
{
	if (item.second == -1)
		return;
	cout << item.first << ",";
	PrintNumber(item.second, 2);
	cout << endl;
}

BitcoinExchange::BitconinException::~BitconinException() throw()
{}

BitcoinExchange::BitconinException::BitconinException(const string& msg): msg(msg)
{}

const char* BitcoinExchange::BitconinException::what() const throw()
{
	return msg.c_str();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	(void)obj;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}
