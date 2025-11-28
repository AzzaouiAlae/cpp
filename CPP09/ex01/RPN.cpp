#include "RPN.hpp"

RPN::RPN(const string& input)
{
	Parse(input);
	PerformCalc(input);
}

RPN::~RPN()
{

}

bool RPN::isOperator(char ch)
{
	if (ch == '*')
		return true;
	if (ch == '-')
		return true;
	if (ch == '+')
		return true;
	if (ch == '/')
		return true;
	return false;
}

bool RPN::isNumber(const string& input, size_t& start)
{
	size_t i = start;

	if (input[i] == '-' && isdigit(input[i + 1]))
		i++;
	while (isdigit(input[i]))
		i++;
	if (i != start)
	{
		start = i - 1;
		return true;
	}
	return false;
}

void RPN::Parse(const string& input)
{
	int digits = 0;
	int ope = 0;
	std::stringstream err;

	for (size_t i = 0; input[i]; i++)
	{
		if (isNumber(input, i))
			digits++;
		else if (isOperator(input[i]))
			ope++;
		else if (input[i] != ' ')
		{
			err << "Error: invalide input\nInvalid char index " << i << " '" << input[i] << "'"; 
			throw RPNException(err.str());
		}
	}
	
	if (digits - 1 > ope)
	{
		err << "Error: invalide input\nToo few operators"; 
		throw RPNException(err.str());
	}
	if (digits - 1 < ope)
	{
		err << "Error: invalide input\nToo many operators"; 
		throw RPNException(err.str());
	}
}

int RPN::firstDigit(const string& str, size_t start)
{
	size_t i;
	if (start == SIZE_MAX)
		return -1;

	while(true)
	{
		i = start;
		if (!str[start])
			break;
		if (isNumber(str, i))
			break;
		start++;
	}

	if (!str[start])
		return -1;
	return start;
}

int RPN::firstOperator(const string& str, size_t start)
{
	size_t i = start;
	if (start == SIZE_MAX)
		return -1;

	while (true)
	{
		i = start;
		if (!str[start])
			break;
		if (isOperator(str[start]) && !isNumber(str, i))
			break;
		start++;
	}
	if (!str[start])
		return -1;
	return start;
}

void RPN::Calc(std::stack<long>& nums, char op)
{
	long n1, n2, num = 0;

	n2 = nums.top();
	nums.pop();
	n1 = nums.top();
	nums.pop();
	switch (op)
	{
	case '*': 
		num = n1*n2; break;
	case '+': 
		num = n1+n2; break;
	case '-': 
		num = n1-n2; break;
	case '/': 
		num = n1/n2; break;
	}
	nums.push(num);
}

void RPN::PerformCalc(const string& input)
{
	std::stack<long> nums;
	long num;
	int i = 0, op = 0;
	char *end;

	i = firstDigit(input, i);
	if (i == -1)
	{
		cout << 0 << endl;
		return ;
	}
	num = std::strtol(&(input[i]), &end, 10);
	i += end - &(input[i]);
	nums.push(num);
	while(true)
	{
		i = firstDigit(input, i);
		op = firstOperator(input, op);
		if (i < 0 && op < 0)
			break;
		if (i < op && i != - 1)
		{
			num = std::strtol(&(input[i]), &end, 10);
			nums.push(num);
			i += end - &(input[i]);
		}
		else
		{
			Calc(nums, input[op]);
			op++;
		}
	}
	cout << nums.top() << endl;
}

RPN::RPNException::~RPNException() throw()
{}

RPN::RPNException::RPNException(const string& msg): msg(msg)
{}

const char* RPN::RPNException::what() const throw()
{
	return msg.c_str();
}
