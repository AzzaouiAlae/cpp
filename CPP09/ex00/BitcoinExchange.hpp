#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <map>

#define string std::string
#define cout std::cout
#define endl std::endl
#define FRACTION_SIZE 4


class BitcoinExchange 
{
	std::map<string, long> database;

	BitcoinExchange& operator=(const BitcoinExchange& obj);
	BitcoinExchange(const BitcoinExchange& obj);

	//databse csv methodes
	void InitDatabase();
	static void PrintPair(const std::pair<string, long> item);

	//file input methodes
	void PrintItem(string& key, long value);
	string DecreaseDay(string dt);

	//csv and input methodes
	void ReadFile(string& data, const string& err, const string& file);
	string NextLine(string& s, int& start);
	void ParseLine(string& line, string& key, string& value, const string& sep);
	void CheckDate(string& date);
	bool isValidDate(int year, int month, int day);
	long ParseNumber(string& completeNum);
	void throwErrors(long& num, char *end, string& completeNum);
	static void PrintNumber(long num, int fracDigits);
public:
	BitcoinExchange();
	~BitcoinExchange();
	void Change(string file);
	void PrintDatabase();
	class BitconinException : public std::exception
	{
		const string msg;
	public:
		~BitconinException() throw();
		BitconinException(const string& msg);
		const char *what() const throw() ;
	};
};
