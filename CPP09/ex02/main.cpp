#include "PmergeMe.hpp"

template <typename ForwardIterator>
bool isSorted(ForwardIterator first, ForwardIterator last)
{
	if (first == last)
		return true;
	ForwardIterator next = first;
	++next;
	while (next != last)
	{
		if (*next < *first)
			return false;
		++first;
		++next;
	}
	return true;
}

void LogNumsToFile(Integer i)
{
	std::string fileName = "file.log";

	std::ofstream os(fileName.c_str(), std::ios::app);
	os << i << "\n";
	os.close();
}

void logFile(std::vector<Integer> &nums, std::vector<Integer> &nums1)
{
	std::string fileName = "file.log";
	std::ofstream os(fileName.c_str());
	os << "Origin nums\n";
	os.close();
	std::for_each(nums.begin(), nums.end(), LogNumsToFile);
	os.open(fileName.c_str(), std::ios::app);
	os << "\nAfter MergeInsert\n";
	os.close();
	std::for_each(nums1.begin(), nums1.end(), LogNumsToFile);
	os.open(fileName.c_str(), std::ios::app);
	os << "\n";
	os.close();
}

void logFile(std::deque<Integer> &nums, std::deque<Integer> &nums1)
{
	std::string fileName = "file.log";
	std::ofstream os(fileName.c_str());
	os << "Origin nums\n";
	os.close();
	std::for_each(nums.begin(), nums.end(), LogNumsToFile);
	os.open(fileName.c_str(), std::ios::app);
	os << "\nAfter MergeInsert\n";
	os.close();
	std::for_each(nums1.begin(), nums1.end(), LogNumsToFile);
	os.open(fileName.c_str(), std::ios::app);
	os << "\n";
	os.close();
}

void GeneralTest()
{
	PmergeMe obj;

	for (int i = 0; i < 500; i++)
	{
		std::srand(std::time(0));
		std::deque<Integer> nums, nums1, nums2;
		nums.clear();
		for (int i = 0; i < 3000; ++i)
		{
			int value = std::rand();
			value = value % 1000;
			if (value < 0)
				value *= -1;
			nums.push_back(value);
		}
		nums1 = nums;
		nums2 = nums;
		struct timeval tv, tv2;
		Integer::Count = 0;
		gettimeofday(&tv, NULL);
		obj.MergeInsert(nums1);
		gettimeofday(&tv2, NULL);
		long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
		long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;
		long time = mcs2 - mcs1;
		std::cout << "Algorithm steps: " << Integer::Count << "\n";
		if (Integer::Count > 30462)
			exit(0);
		std::string s = isSorted(nums1.begin(), nums1.end()) ? "true\n" : "false\n";
		std::cout << "isSorted: " << s << "Time: " << time << " ms\n";
		if (nums.size() != nums1.size())
			std::cout << "num1 has wrong size: " << nums1.size() << " sould be: " << nums.size() << '\n';
		std::sort(nums.begin(), nums.end());
		std::string fileName = "file.log";
		logFile(nums2, nums1);
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

int main(int argC, char *argV[])
{
	(void)argC; (void)argV;
	// GeneralTest();
	PmergeMe mergeInsertion;
	try {
		mergeInsertion.MISort(argV);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
