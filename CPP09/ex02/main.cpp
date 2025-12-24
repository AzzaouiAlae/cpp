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
	os << i << " ";
	os.close();
}

void logFile(std::vector<Integer> &nums, std::vector<Integer> &nums1, std::vector<Integer> &nums2)
{
	std::string fileName = "file.log";
	std::ofstream os(fileName.c_str());
	os << "Origin nums\n";
	os.close();
	std::for_each(nums.begin(), nums.end(), LogNumsToFile);


	os.open(fileName.c_str(), std::ios::app);
	os << "\n\nAfter MergeInsert\n";
	os.close();
	std::for_each(nums1.begin(), nums1.end(), LogNumsToFile);
	os.open(fileName.c_str(), std::ios::app);
	os << "\n";
	os.close();


	os.open(fileName.c_str(), std::ios::app);
	os << "\nSorted nums\n";
	os.close();
	std::for_each(nums2.begin(), nums2.end(), LogNumsToFile);
	os.open(fileName.c_str(), std::ios::app);
	os << "\n";
	os.close();
}

float log2(float num)
{
	return std::log(num) / std::log(2.0);
}

void GeneralTest()
{
	PmergeMe obj;
	int numberOfTests = 500000;
	int numberOfItems = 33;
	int maxGenNum = numberOfItems * 100;

	for (int i = 0; i < numberOfTests; i++)
	{
		std::srand(std::time(0));
		std::vector<Integer> numsToSort, originalNums, numsSortedByCpp;
		numsToSort.clear();
		for (int i = 0; i < numberOfItems; ++i)
		{
			int value = std::rand();
			value = value % maxGenNum;
			if (value < 0)
				value *= -1;
			numsToSort.push_back(value);
		}
		originalNums = numsToSort;
		numsSortedByCpp = numsToSort;
		struct timeval tv, tv2;
		Integer::Count = 0;
		gettimeofday(&tv, NULL);
		obj.MergeInsert(numsToSort);
		gettimeofday(&tv2, NULL);
		

		long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
		long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;
		long time = mcs2 - mcs1;


		float ItemsCount = numberOfItems;
		int NumberOfComparisons = Integer::Count;
		int maxNumberOfComparisons = ceil(ItemsCount * log2(ItemsCount) - ItemsCount * 1.25);

		std::cout << i + 1 << '\n';
		std::cout << "max number of Comparisons: " << maxNumberOfComparisons << "\n";
		std::cout << "Algorithm Comparisons: " << NumberOfComparisons << "\n";
		std::string s = isSorted(numsToSort.begin(), numsToSort.end()) ? "true\n" : "false\n";
		std::cout << "isSorted: " << s << "Time: " << time << " ms\n";
		if (numsToSort.size() != originalNums.size())
			std::cout << "num1 has wrong size: " << originalNums.size() << " sould be: " << numsToSort.size() << '\n';
		std::sort(numsSortedByCpp.begin(), numsSortedByCpp.end());
		if (s == "false\n" || numsToSort.size() != originalNums.size() || NumberOfComparisons > maxNumberOfComparisons)
		{
			logFile(originalNums, numsToSort, numsSortedByCpp);
			exit(0);
		}
		for (int i = 0; i < (int)numsToSort.size(); i++)
		{
			if (numsToSort[i] != numsSortedByCpp[i])
			{
				std::cout << "Corrupted output\n";
				logFile(originalNums, numsToSort, numsSortedByCpp);
				exit(0);
			}
		}
		std::cout << "\n";
	}
}



int main(int argC, char *argV[])
{
	(void)argC; (void)argV;
	PmergeMe mergeInsertion;
	try {
		GeneralTest();
		mergeInsertion.MISort(argV);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
