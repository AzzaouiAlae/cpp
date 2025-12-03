#include <iostream>
#include <vector>
#include <cmath>
#include <stdint.h>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>   // rand, srand
#include <ctime>
#include <iterator>
#include <map>

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

	bool operator!=(const Int &other) const
	{
		Count++;
		return value != other.value;
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

int lvl = 0;

void PrintList(std::vector<Int> nums)
{
	std::cout << "----------- " << lvl << " -----------\n";
	std::cout << nums[0];
	for(int i = 1; i < (int)nums.size(); i++)
		std::cout <<  ", " << nums[i];
	std::cout << "\n"; 
}

void MergeInsert(std::vector<Int > &nums)
{
	if (nums.size() < 2)
		return;
	// PrintList(nums);
	std::vector<Int> a, b, restoredB;
	MakePairs(nums, a, b);
	// lvl++;
	MergeInsert(a);
	// lvl--;
	restB(a, b, restoredB);
	nums.clear();
	nums.push_back(restoredB[0]);
	int tk_ = 0, tk, m, u = 0;
	const int bN = restoredB.size();
	const int aN = a.size();
	for(int k = 2; tk_ < bN - 1; ++k)
	{
		tk = t_sequence(k);
		m = std::min(tk + 1, bN);;
		while(u < tk && u < aN) {
            nums.push_back(a[u++]);
        }
		for(int i = m; i > tk_ + 1; i--)
			BinaryInsertion(nums, restoredB[i - 1]);
		tk_ = tk;
	}
	for (;u < aN; u++)
		nums.push_back(a[u]);
	
	// PrintList(nums);

}

#include <fstream>
#include <unistd.h>

void print(Int i)
{
	std::string fileName =  "file.log";

	std::ofstream os(fileName.c_str(), std::ios::app);
	os << i << "\n";
	os.close();
}

void logFile(std::vector<Int>& nums, std::vector<Int>& nums1)
{
	std::string fileName =  "file.log";
	std::ofstream os(fileName.c_str());
	os << "Origin nums\n";
	os.close();
	std::for_each(nums.begin(), nums.end(), print);
	os.open(fileName.c_str(), std::ios::app);
	os << "\nAfter MergeInsert\n";
	os.close();
	std::for_each(nums1.begin(), nums1.end(), print);
	os.open(fileName.c_str(), std::ios::app);
	os << "\n";
	os.close();
}

int main()
{
	for(int i = 0; i < 1000; i++)
	{
		std::srand(std::time(0));
		std::vector<Int> nums;
		std::vector<Int> nums1;
		nums.clear();
    	for (int i = 0; i < 21; ++i)
    	{
    	    int value = std::rand();
			value = value % 1000;
    	    nums.push_back(value);
    	}
		nums1 = nums;
		struct timeval tv, tv2;
		Int::Count = 0;
    	gettimeofday(&tv, NULL);
		MergeInsert(nums1);
		gettimeofday(&tv2, NULL);
		long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
		long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;
		long time = mcs2 - mcs1;
		std::cout << "lgorithm steps: " << Int::Count << "\n";
		std::string s = isSorted(nums1.begin(), nums1.end()) ? "true\n" : "false\n";
		std::cout <<"isSorted: " << s << "Time: " << time << " ms\n";
		if (nums.size() != nums1.size())
			std::cout << "num1 has wrong size: " <<  nums1.size() << " sould be: " << nums.size() << '\n';
		std::sort(nums.begin(), nums.end());
		std::string fileName =  "file.log";
		{
			logFile(nums, nums1);
			
		}
		for (int i = 0; i < (int)nums.size(); i++)
		{
			if (nums[i] != nums1[i])
			{
				std::cout << "Corrupted output\n";
				logFile(nums, nums1);
				exit(0);
			}
			
		}
		if (s == "false\n" || nums.size() != nums1.size())
				exit(0);
		
		std::cout << "\n";
	}
}
