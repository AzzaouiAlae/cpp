#include <iostream>
#include <vector>
#include <cmath>
#include <stdint.h>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>   // rand, srand
#include <ctime>
#include <iterator>

template <typename ForwardIterator>
bool isSorted(ForwardIterator first, ForwardIterator last) {
    if (first == last) {
        return true; // Empty range is considered sorted
    }

    ForwardIterator next = first;
    ++next;

    while (next != last) {
        if (*next < *first) { // Using operator< for ascending order
            return false;
        }
        ++first;
        ++next;
    }
    return true;
}

class Int
{
	unsigned char c;
	int idxs[35];

public:
	int value;
	static int Count;
	void push(int idx)
	{
		idxs[c++] = idx;
	}

	int pop()
	{
		return idxs[--c];
	}

	bool operator<(const Int &other) const
	{
		Count++;
		return value < other.value;
	}
	
	Int(int value = 0) : c(0), value(value)
	{}

	Int(Int &obj) : c(obj.c), value(obj.value)
	{
		std::copy(obj.idxs, obj.idxs + c, idxs);
	}

	Int(const Int &obj) : c(obj.c), value(obj.value)
	{
		std::copy(obj.idxs, obj.idxs + c, idxs);
	}
	// Copy Assignment Operator - C++98
    Int& operator=(const Int& other)
    {
        if (this != &other)
        {
            c = other.c;
            value = other.value;
            std::copy(other.idxs, other.idxs + c, idxs);
        }
        return *this;
    }
    
    // Destructor (default is fine, no manual cleanup needed)
    ~Int() {}
};

int Int::Count = 0; 

std::ostream &operator<<(std::ostream &o, const Int &i)
{
	o << i.value;
	return o;
}


size_t t_sequence(size_t k)
{
	size_t powerOfTwo = (1 << (k + 1));

	int sign = (k % 2 == 0) ? 1 : -1;

	size_t jacobsthal_number = (powerOfTwo + sign) / 3;

	return jacobsthal_number - 1;
}

void BinaryInsertion(std::vector<Int> &d, const Int &item)
{
	std::vector<Int>::iterator it = std::lower_bound(d.begin(), d.end(), item);
    
    d.insert(it, item);
}

void MakePairs(std::vector<Int> &nums, std::vector<Int> &a, std::vector<Int> &b)
{
	int n = nums.size() - 1;
	a.reserve(n / 2);
	b.reserve(n / 2 + 1);
	for(int i = 0; i < n; i += 2)
	{
		if (nums[i] < nums[i + 1])
		{
			nums[i + 1].push(a.size());
			a.push_back(nums[i + 1]);
			b.push_back(nums[i]);
		}
		else
		{
			nums[i].push(a.size());
			a.push_back(nums[i]);
			b.push_back(nums[i + 1]);
		}
	}
	if ((n + 1) % 2)
		b.push_back(nums[n]);
}

void restB(std::vector<Int>& a, std::vector<Int>& b, std::vector<Int>& restorB)
{
	int n = (int)a.size();
	restorB.reserve(b.size());
	for(int i = 0; i < n; i++)
	{
		int idx = a[i].pop();
		restorB.push_back(b[idx]);
	}
	if ((int)b.size() > n)
		restorB.push_back(b[n]);
}

void MergeInsert(std::vector<Int > &nums)
{
	if (nums.size() < 2)
		return;
	std::vector<Int> a, b, restoredB;
	MakePairs(nums, a, b);
	MergeInsert(a);
	restB(a, b, restoredB);
	nums.clear();
	nums.push_back(restoredB[0]);
	int tk_ = 0, tk, m, u = 0;
	const int bN = restoredB.size();
	const int aN = a.size();
	for(int k = 1; tk_ < bN; ++k)
	{
		tk = t_sequence(k);
		m = std::min(tk, bN - 1);;
		while(u < tk && u < aN) {
            nums.push_back(a[u++]);
        }
		for(int i = m; i > tk_ + 1; i--)
			BinaryInsertion(nums, restoredB[i - 1]);
		tk_ = tk;
	}
	for (;u < aN; u++)
		nums.push_back(a[u]);
}



void MergeInsertion2(std::vector<Int>& nums)
{
	int n = nums.size() - 1;

	if (n < 2)
		return;
	std::vector<Int> a, b, restoredB;
	a.reserve((n + 1) / 2);
	b.reserve((n + 1) / 2 + 1);
	restoredB.reserve((n + 1) / 2 + 1);
	for(int i = 0; i < n ; i += 2)
	{
		Int& var1 = nums[i];
		Int& var2 = nums[i + 1];
		if (var1 < var2)
		{
			var2.push(a.size());
			a.push_back(var2);
			b.push_back(var1);
		}
		else
		{
			var1.push(a.size());
			a.push_back(var1);
			b.push_back(var2);
		}
	}

	if ((n + 1) % 2)
		b.push_back(nums[n]);
	MergeInsertion2(a);
	n = a.size();
	for(int i = 0; i < n; i++)
	{
		int idx = a[i].pop();
		restoredB.push_back(b[idx]);
	}
	if (n < (int)b.size())
		restoredB.push_back(b[n]);
	nums.clear();
	nums.push_back(restoredB[0]);
	int k = 2, tk, tk_ = t_sequence(1), m, u = 0;
	int aN = a.size();
	n = restoredB.size();
	while(tk_ < n)
	{
		tk = t_sequence(k);
		m = std::min(tk, n - 1);
		while(u < m && u < aN)
			nums.push_back(a[u++]);
		for(int i = m; i > tk_ + 1; i--)
		{
			std::vector<Int>::iterator it = 
			std::lower_bound(nums.begin(), nums.end(), restoredB[i - 1]);
			nums.insert(it, restoredB[i - 1]);
		}
		tk_ = tk;
		k++;
	}
	while(u < aN)
		nums.push_back(a[u++]);
}

int main()
{
	std::srand(std::time(0));
    
	std::vector<Int> nums;

    for (int i = 0; i < 3000; ++i)
    {
        int value = std::rand();
        nums.push_back(value);
    }

	struct timeval tv, tv2;

    gettimeofday(&tv, NULL);
	// std::sort(nums.begin(), nums.end());
	// MergeInsert(nums);
	MergeInsertion2(nums);
	
	gettimeofday(&tv2, NULL);

	long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;

	long time = mcs2 - mcs1;
	std::cout << "Number of Operations: "<< Int::Count ;
	std::string s = isSorted(nums.begin(), nums.end()) ? "true\n" : "false\n";
	std::cout << "\n" <<"isSorted: " << s << "Time: " << time << " ms\n\n";

	// Print(nums, 0, 0, nums.size());
	std::cout << "\n";
	return 0;
}
