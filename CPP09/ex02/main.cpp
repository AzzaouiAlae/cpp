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

int computeSum(int n)
{
    int sum = 0;

    for (int k = 1; k <= n; ++k)
    {
        double value = log2((3.0 / 4.0) * k);
        sum += static_cast<int>(std::ceil(value));
    }

    return sum;
}

std::vector<std::vector<Integer> > getAllArrangements(int n, int max)
{
	std::vector<Integer> list;

	for(int i = 1; i <= n; i++)
	{
		list.push_back(i);
	}
    std::vector<std::vector<Integer> > allArrangements;

    do {
        allArrangements.push_back(list);
    } while (std::next_permutation(list.begin(), list.end()) && (int)allArrangements.size() < max);
    return allArrangements;
}

void GeneralTest(int numberOfItems, int numberOfTests = 1000000, int skip = 0)
{
	PmergeMe obj;

	std::vector<Integer> list, numsToSort, originalNums, numsSortedByCpp;

	for(int i = 1; i <= numberOfItems; i++)
	{
		list.push_back(i);
	}

	bool var = true;

	for (int i = 0; i < numberOfTests && var; i++)
	{
		numsToSort = list;
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


		int NumberOfComparisons = Integer::Count;
		int maxNumberOfComparisons = computeSum(numberOfItems);

		
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
		for(int i = 0; i <= skip; i++)
		{
			var = std::next_permutation(list.begin(), list.end());
			if (!var)
				break;
		}
	}
}

int main(int argC, char *argV[])
{
	(void)argC; (void)argV;
	PmergeMe mergeInsertion;
	try {
		for(int i = 1; i <= 33; i++)
		{
			if (i < 7)
			{
				GeneralTest(i, 100000);
			}
			else
			{
				GeneralTest(i, 100000, i * log2(i));
			}
		}
		mergeInsertion.MISort(argV);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
