#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdint.h>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <deque>
#include <sstream>
#include <fstream>
#include <unistd.h>

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
        {
            // std::cout <<"next :" <<next->value << "first";
			return false;
        }
		++first;
		++next;
	}
	return true;
}

void LogNumsToFile(Int i)
{
	std::string fileName = "file.log";

	std::ofstream os(fileName.c_str(), std::ios::app);
	os << i << " ";
	os.close();
}

void logFile(std::vector<Int> &nums, std::vector<Int> &nums1, std::vector<Int> &nums2)
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


void GeneralTest(int numberOfItems, int numberOfTests = 1000000, int skip = 0)
{
	PmergeMe obj;

	std::vector<Int> list, numsToSort, originalNums, numsSortedByCpp;

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
		Int::Count = 0;
		gettimeofday(&tv, NULL);
		obj.sort(numsToSort);
        numsToSort = obj.getVectorNums();
		gettimeofday(&tv2, NULL);
		

		long mcs1 = (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
		long mcs2 = (long)tv2.tv_sec * 1000 * 1000 + tv2.tv_usec;
		long time = mcs2 - mcs1;


		int NumberOfComparisons = Int::Count;
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
			if (numsToSort[i].value != numsSortedByCpp[i].value)
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

void	printResulte(std::deque<Int>& dq_nums, std::string str)
{
	std::cout << str << ": " ;
	for (size_t i = 0; i < dq_nums.size(); i++)
	{
		std::cout << dq_nums[i] << " " ;
	}
	std::cout << std::endl;
	
}

void	printResulte(std::vector<Int>& v_nums, std::string str)
{
	std::cout << str << ": " ;
	for (size_t i = 0; i < v_nums.size(); i++)
	{
		std::cout << v_nums[i] << " " ;
	}
	std::cout << std::endl;
}
int main(int argc, char const *argv[])
{

    if ( argc <= 1 )
    {
        std::cout << "there is no numbers to sort !!\n";
        return 0;
    }

    std::vector<std::string> v_args;
    for (int i = 1; i < argc; i++)
        v_args.push_back(argv[i]);
    try
    {
        // int n = 3000;
		// GeneralTest(n, 1000000, 10);
		std::deque<std::string> dq_args(v_args.begin(), v_args.end());

        PmergeMe	v_algo(v_args);
	
		printResulte(v_algo.getVectorNums(), "vector befor");
		v_algo.initTime();

        v_algo.sort(v_algo.getVectorNums());
	
		std::cout << "time of sorting a vector = " << v_algo.timeOfSorting() << "ms\n";
		printResulte(v_algo.getVectorNums(), "vector after");

		std::cout << "\n==================================================\n\n";
		PmergeMe	dq_algo(dq_args);

		v_algo.initTime();

		printResulte(dq_algo.getDequeNums(), "deque befor");

		dq_algo.sort(dq_algo.getDequeNums());

		std::cout << "time of sorting a deque = " << v_algo.timeOfSorting() << "ms\n";
		printResulte(dq_algo.getDequeNums(), "deque after");

 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
