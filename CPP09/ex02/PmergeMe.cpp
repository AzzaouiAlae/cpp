#include "PmergeMe.hpp"

size_t PmergeMe::t_sequence(size_t k)
{
	size_t powerOfTwo = (1 << (k + 1));

	int sign = (k % 2 == 0) ? 1 : -1;

	size_t jacobsthal_number = (powerOfTwo + sign) / 3;

	return jacobsthal_number - 1;
}

void PmergeMe::MakePairs(std::vector<Integer> &nums, std::vector<Integer> &a, std::vector<Integer> &b)
{
	int n = nums.size() - 1;
	a.reserve(n / 2);
	b.reserve(n / 2 + 1);
	for (int i = 0; i < n; i += 2)
	{
		if (nums[i] < nums[i + 1])
		{
			nums[i + 1].saveIndex(a.size());
			a.push_back(nums[i + 1]);
			b.push_back(nums[i]);
		}
		else
		{
			nums[i].saveIndex(a.size());
			a.push_back(nums[i]);
			b.push_back(nums[i + 1]);
		}
	}
	if ((n + 1) % 2)
		b.push_back(nums[n]);
}

void PmergeMe::restB(std::vector<Integer> &a, std::vector<Integer> &b, std::vector<Integer> &restorB)
{
	int n = (int)a.size();
	restorB.reserve(b.size());
	for (int i = 0; i < n; i++)
	{
		int idx = a[i].GetIndex();
		restorB.push_back(b[idx]);
	}
	if ((int)b.size() > n)
		restorB.push_back(b[n]);
}

void PmergeMe::MergeInsert(std::vector<Integer> &nums)
{
	if (nums.size() < 2)
		return;
	std::vector<Integer> a, b, restoredB;
	MakePairs(nums, a, b);
	MergeInsert(a);
	restB(a, b, restoredB);
	nums.clear();
	nums.push_back(restoredB[0]);
	int tk_ = 0, tk, m, u = 0;
	const int bN = restoredB.size();
	const int aN = a.size();
	for (int k = 2; tk_ < bN - 1; ++k)
	{
		tk = t_sequence(k);
		m = std::min(tk + 1, bN);
		while (u < tk && u < aN - 1)
			nums.push_back(a[u++]);
		if (tk + 1 >= bN && u < aN && aN < bN)
			nums.push_back(a[u++]);
		for (int i = m, j = 0; i > tk_ + 1; i--, j++)
		{
			std::vector<Integer>::iterator it =
				std::lower_bound(nums.begin(), nums.end() - j, restoredB[i - 1]);
			nums.insert(it, restoredB[i - 1]);
		}
		tk_ = tk;
	}
	for (; u < aN; u++)
		nums.push_back(a[u]);
}

void PmergeMe::MakePairs(std::deque<Integer>& nums, std::deque<Integer> &a, std::deque<Integer> &b)
{
	int n = nums.size() - 1;
	for (int i = 0; i < n; i += 2)
	{
		if (nums[i] < nums[i + 1])
		{
			nums[i + 1].saveIndex(a.size());
			a.push_back(nums[i + 1]);
			b.push_back(nums[i]);
		}
		else
		{
			nums[i].saveIndex(a.size());
			a.push_back(nums[i]);
			b.push_back(nums[i + 1]);
		}
	}
	if ((n + 1) % 2)
		b.push_back(nums[n]);
}

void PmergeMe::restB(std::deque<Integer> &a, std::deque<Integer> &b, std::deque<Integer> &restorB)
{
	int n = (int)a.size();
	for (int i = 0; i < n; i++)
	{
		int idx = a[i].GetIndex();
		restorB.push_back(b[idx]);
	}
	if ((int)b.size() > n)
		restorB.push_back(b[n]);
}

void PmergeMe::MergeInsert(std::deque<Integer> &nums)
{
	if (nums.size() < 2)
		return;
	std::deque<Integer> a, b, restoredB;
	MakePairs(nums, a, b);
	MergeInsert(a);
	restB(a, b, restoredB);
	nums.clear();
	nums.push_back(restoredB[0]);
	int tk_ = 0, tk, m, u = 0;
	const int bN = restoredB.size();
	const int aN = a.size();
	for (int k = 2; tk_ < bN - 1; ++k)
	{
		tk = t_sequence(k);
		m = std::min(tk + 1, bN);
		while (u < tk && u < aN - 1)
			nums.push_back(a[u++]);
		if (tk + 1 >= bN && u < aN && aN < bN)
			nums.push_back(a[u++]);
		for (int i = m, j = 0; i > tk_ + 1; i--, j++)
		{
			std::deque<Integer>::iterator it =
				std::lower_bound(nums.begin(), nums.end() - j, restoredB[i - 1]);
			nums.insert(it, restoredB[i - 1]);
		}
		tk_ = tk;
	}
	for (; u < aN; u++)
		nums.push_back(a[u]);
}

std::vector<std::string> splitString(const std::string& s, const std::string& delimiter) 
{
    std::vector<std::string> tokens;
    std::string::size_type lastPos = 0;
    std::string::size_type pos = s.find(delimiter, lastPos);

    while (pos != std::string::npos) 
	{
		if (s.substr(lastPos, pos - lastPos) != delimiter)
			tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = pos + delimiter.length();
        pos = s.find(delimiter, lastPos);
    }
    tokens.push_back(s.substr(lastPos));
    return tokens;
}

bool Integer::isValidNumber(const std::string& s, long num, const std::string& end)
{
	if (s == "nan" || s == "nanf")
		return false;
	if (s == "inf" || s == "-inf" || s == "+inf")
		return false;
	if (s == "inff" || s == "-inff" || s == "+inff")
		return false;
	if (s == "")
		return false;
	if (end != "f" && end != "")
		return false;
	if (errno == ERANGE)
		return false;
	if (num > 2147483647)
		return false;
	if (num < 0)
		return false;
	return true;
}

Integer::Int (const std::string& s) 
{
	c = 0;
	char *end;
	long num = std::strtol(s.c_str(), &end, 10);
	
	value = 0;
	if (!isValidNumber(s, num, end)) 
	{
		std::stringstream st;
		st << "Error: Invalid input '" << s << '\'';
		throw PmergeMeException(st.str());
	}
	else
		value = num;
}

void PmergeMe::Parse(char *argV[])
{
	if (argV[1] == 0)
		throw PmergeMeException("Error: empty argument");
	for(int i = 1; argV[i]; i++)
	{
		std::vector<std::string> strs = splitString(argV[i], " ");
		for(int i = 0; i < (int)strs.size(); i++)
		{
			if (strs[i] == "")
				continue;
			Int num(strs[i]);
			vNums.push_back(num);
			dNums.push_back(num);
		}
	}
	if (vNums.size() == 0)
		throw PmergeMeException("Error: empty argument");
}

void PmergeMe::MISortVector()
{
	struct timeval tv, tv2;

	gettimeofday(&tv, NULL);
	MergeInsert(vNums);
	gettimeofday(&tv2, NULL);

	if (vNums.size() > 20)
		std::cout << "\n";
	std::cout << "After : ";
	for(int i = 0; i < (int)vNums.size(); i++)
		std::cout << vNums[i] << " ";
	std::cout << "\n";

	if (vNums.size() > 20)
		std::cout << "\n";
	long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;
	long time = mcs2 - mcs1;
	std::cout << "Time to process a range of " << vNums.size() << 
				" elements with std::vector : " << time << " ms\n";
}

void PmergeMe::MISortDeque()
{
	struct timeval tv, tv2;

	gettimeofday(&tv, NULL);
	MergeInsert(dNums);
	gettimeofday(&tv2, NULL);

	long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;
	long time = mcs2 - mcs1;
	std::cout << "Time to process a range of " << dNums.size() << 
				" elements with std::deque : " << time << " ms\n";
}

void PmergeMe::MISort(char *argV[])
{
	Parse(argV);
	if (vNums.size() > 20)
		std::cout << "\n";
	std::cout << "Before: ";
	for(int i = 0; i < (int)vNums.size(); i++)
		std::cout << vNums[i] << " ";
	std::cout << "\n";
	MISortVector();
	Int::Count = 0;
	MISortDeque();
	std::cout << "Number of comparisons: " << Int::Count << "\n";
}

PmergeMe::PmergeMeException::~PmergeMeException() throw()
{}

PmergeMe::PmergeMeException::PmergeMeException(const std::string& msg): msg(msg)
{}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return msg.c_str();
}

Integer::Int(int val): value(val)
{
	c = 0;
}

Integer::~Int() {}

Integer::Int(const Int &obj) : c(obj.c), value(obj.value)
{
	std::copy(obj.idxs, obj.idxs + c, idxs);
}

int PmergeMe::Int::Count = 0;

void Integer::saveIndex(int idx)
{
	idxs[c++] = idx;
}

int Integer::GetIndex()
{
	return idxs[--c];
}

bool Integer::operator<(const Int &other) const
{
	Count++;
	return value < other.value;
}

Integer &Integer::operator=(const Int &other)
{
	if (this != &other)
	{
		c = other.c;
		value = other.value;
		std::copy(other.idxs, other.idxs + c, idxs);
	}
	return *this;
}

bool Integer::operator!=(const Int &other) const
{
	Count++;
	return value != other.value;
}

std::ostream &operator<<(std::ostream &o, const Integer &i)
{
	o << i.value;
	return o;
}