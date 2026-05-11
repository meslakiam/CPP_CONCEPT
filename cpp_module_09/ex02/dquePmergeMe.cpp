#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::deque<std::string>  dq_str)
{
    for (size_t i = 0; i < dq_str.size(); i++)
    {
        char * end;
        errno = 0;
        long n = strtol(dq_str[i].c_str(),&end, 10);
        if ( *end != '\0' )
            throw std::runtime_error("non-digit character detected !!");
        if ( errno == ERANGE || n > 2147483647 )
            throw std::out_of_range(("number out_of_range !!"));
        if ( n < 0 )
            throw std::runtime_error("negative number detected !!");
        std::deque<Int>::iterator it = std::find(_dq_nums.begin(), _dq_nums.end(),Int(n));
        if ( it != _dq_nums.end() )
            throw std::runtime_error("duplicated number detected !!");

        _dq_nums.push_back(Int((int)n));
    }
}

void PmergeMe::sort(std::deque<Int>&  _dq_nums)
{
    if (_dq_nums.empty())
        return;

    algorithm(_dq_nums);
}

void PmergeMe::algorithm(std::deque<Int>& dq_largeNums)
{
    std::deque<Int> dq_smallNums;
    
    if (dq_largeNums.size() == 1)
        return;

    PairwiseComparison(dq_largeNums, dq_smallNums);
    mapThePairs(dq_largeNums, dq_smallNums);

    algorithm(dq_largeNums);

    insertion(dq_largeNums, dq_smallNums);
    for (size_t i = 0; i < dq_largeNums.size(); i++)
    {
        if (!dq_largeNums[i].index.empty())
            dq_largeNums[i].index.pop_back();
    }

}

void PmergeMe::PairwiseComparison(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums)
{
    std::deque<Int> v_tmpNumbers;
    for (size_t i = 0; i < dq_largeNums.size(); i += 2)
    {
        if (i == dq_largeNums.size() - 1)
        {
            dq_smallNums.push_back(dq_largeNums[i]);
            break;
        }
        if (dq_largeNums[i] < dq_largeNums[i + 1])
        {
            v_tmpNumbers.push_back(dq_largeNums[i + 1]);
            dq_smallNums.push_back(dq_largeNums[i]);
        }
        else
        {
            v_tmpNumbers.push_back(dq_largeNums[i]);
            dq_smallNums.push_back(dq_largeNums[i + 1]);
        }
    }
    dq_largeNums = v_tmpNumbers;
}


void PmergeMe::mapThePairs(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums)
{
    for (size_t i = 0; i < dq_largeNums.size(); i++)
        dq_largeNums[i].index.push_back(i);
    for (size_t i = 0; i < dq_smallNums.size(); i++)
        dq_smallNums[i].index.push_back(i);
}

void PmergeMe::orderedThePair(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums, std::deque<Int>& dq_smallOrderedPaire)
{
    for (size_t i = 0; i < dq_largeNums.size(); i++)
    {
        int pairIndex = dq_largeNums[i].index.back();
        std::deque<Int>::iterator it = std::find_if(dq_smallNums.begin(), dq_smallNums.end(),
                                                      HasSameIndex(pairIndex));
        if (it == dq_smallNums.end())
            continue;

        dq_smallOrderedPaire.push_back(*it);
        dq_smallNums.erase(it);
    }
    if ( !dq_smallNums.empty() )
    {
        dq_smallOrderedPaire.push_back(dq_smallNums.back());
        dq_smallNums.erase(dq_smallNums.end() - 1);

    }

}


void PmergeMe::insertion(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums)
{
    std::deque<Int> dq_mainChain;
    std::deque<Int> dq_smallOrderedPaire;

    orderedThePair(dq_largeNums, dq_smallNums, dq_smallOrderedPaire);

    dq_mainChain.push_back(dq_smallOrderedPaire[0]);

    std::vector<int> jacob = JacobSequenceIndexes(dq_largeNums.size());


    int prevJacob = 0;

    for (int i = 0; i < (int)jacob.size(); i++)
    {
        int curr = jacob[i];
        if (curr >= (int)dq_smallOrderedPaire.size())
            curr = (int)dq_smallOrderedPaire.size() - 1;

        for (int j = prevJacob; j < curr; j++)
            dq_mainChain.push_back(dq_largeNums[j]);

        // Walk backwards inserting b's with lower_bound up to paired a
        for (int j = curr ; j > prevJacob; j--)
        {
            if (j == 0)
                continue;
            if (j >= (int)dq_smallOrderedPaire.size())
                continue;

            std::deque<Int>::iterator it = std::lower_bound(
                dq_mainChain.begin(), dq_mainChain.end(), dq_smallOrderedPaire[j]);
            dq_mainChain.insert(it, dq_smallOrderedPaire[j]);
        }
        prevJacob = curr;
    }

    // Push remaining a's FREE (not covered by jacob)
    for (int j = prevJacob; j < (int)dq_largeNums.size(); j++)
        dq_mainChain.push_back(dq_largeNums[j]);

    // Insert remaining b's
    for (int j = prevJacob + 1; j < (int)dq_smallOrderedPaire.size(); j++)
    {
        if (j == 0)
            continue;

        std::deque<Int>::iterator it = std::lower_bound(
            dq_mainChain.begin(), dq_mainChain.end(), dq_smallOrderedPaire[j]);
        dq_mainChain.insert(it, dq_smallOrderedPaire[j]);
    }

    

    dq_largeNums.clear();
    dq_largeNums = dq_mainChain;
}

std::deque<Int>& PmergeMe::getDequeNums()
{
    return _dq_nums;
}

void PmergeMe::setNums(std::deque<Int>& dq_args)
{
    _dq_nums  = dq_args;
}

