#include "PmergeMe.hpp"

int Int::Count = 0;
clock_t PmergeMe::_g_startTime = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> v_str)
{
    for (size_t i = 0; i < v_str.size(); i++)
    {
        char * end;
        errno = 0;
        long n = strtol(v_str[i].c_str(),&end, 10);
        if ( *end != '\0' )
            throw std::runtime_error("non-digit character detected !!");
        if ( errno == ERANGE || n > 2147483647 )
            throw std::out_of_range(("number out_of_range !!"));
        if ( n < 0 )
            throw std::runtime_error("negative number detected !!");
        std::vector<Int>::iterator it = std::find(_v_nums.begin(), _v_nums.end(),Int(n));
        if ( it != _v_nums.end() )
            throw std::runtime_error("duplicated number detected !!");

        _v_nums.push_back(Int((int)n));
    }
}


PmergeMe::PmergeMe(PmergeMe& other)
{
    this->_v_nums = other._v_nums;
    this->_dq_nums = other._dq_nums;
}
PmergeMe&   PmergeMe::operator=(PmergeMe& other)
{
    if ( this == &other )
        return *this;
    
    this->_v_nums = other._v_nums;
    this->_dq_nums = other._dq_nums;

    return *this;
}

PmergeMe::~PmergeMe() {}

void print(std::vector<Int> v)
{
    std::cout << "\n------------------------------\n";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    
    std::cout << "\n------------------------------\n";
}

void PmergeMe::sort(std::vector<Int>& nums)
{
    if (nums.empty())
        return;

    std::cout << "non sorted\n";

    print(nums);
    algorithm(nums);
    _v_nums = nums;
    std::cout << "sorted\n";

    print(nums);
    
}

void PmergeMe::PairwiseComparison(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums)
{
    std::vector<Int> v_tmpNumbers;
    for (size_t i = 0; i < v_largeNums.size(); i += 2)
    {
        if (i == v_largeNums.size() - 1)
        {
            v_smallNums.push_back(v_largeNums[i]);
            break;
        }
        if (v_largeNums[i] < v_largeNums[i + 1])
        {
            v_tmpNumbers.push_back(v_largeNums[i + 1]);
            v_smallNums.push_back(v_largeNums[i]);
        }
        else
        {
            v_tmpNumbers.push_back(v_largeNums[i]);
            v_smallNums.push_back(v_largeNums[i + 1]);
        }
    }
    v_largeNums = v_tmpNumbers;
}

void PmergeMe::mapThePairs(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums)
{
    for (size_t i = 0; i < v_largeNums.size(); i++)
        v_largeNums[i].index.push_back(i);
    for (size_t i = 0; i < v_smallNums.size(); i++)
        v_smallNums[i].index.push_back(i);
}

// Real Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
std::vector<int> PmergeMe::JacobSequenceIndexes(size_t size)
{
    std::vector<int> jacob;
    if (size <= 1)
        return jacob;

    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (true)
    {
        int next = seq.back() + 2 * seq[seq.size() - 2];
        if ((size_t)next >= size)
            break;
        seq.push_back(next);
    }
    for (size_t i = 2; i < seq.size(); i++)
        jacob.push_back(seq[i]);

    return jacob;
}

void PmergeMe::orderedThePair(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums,
                               std::vector<Int>& v_smallOrderedPaire)
{
    // std::cout << "**************returned large num in recursion**********\n" ;
    // print(v_largeNums);
    
    // std::cout << "********************************************************\n" ;

    for (size_t i = 0; i < v_largeNums.size(); i++)
    {
        int pairIndex = v_largeNums[i].index.back();
        std::vector<Int>::iterator it = std::find_if(v_smallNums.begin(), v_smallNums.end(),
                                                      HasSameIndex(pairIndex));
        if (it == v_smallNums.end())
            continue;

        v_smallOrderedPaire.push_back(*it);
        v_smallNums.erase(it);
    }
    if ( !v_smallNums.empty() )
    {
        v_smallOrderedPaire.push_back(v_smallNums.back());
        v_smallNums.erase(v_smallNums.end() - 1);
    }
    
    // std::cout << "=========v_smallOrderedPaire after orderd them=========\n" ;
    // for (size_t i = 0; i < v_smallOrderedPaire.size() && i < v_largeNums.size(); i++)
    // {
    //     std::cout  << " large: " << v_largeNums[i].value << " large index: " << v_largeNums[i].index.back();
    //     std::cout << " small: "  <<  v_smallOrderedPaire[i].value << " small index: ";
    //     if ( v_smallOrderedPaire[i].index.empty() )
    //         std::cout << " no index found for small ";
    //     else
    //         std::cout  << v_smallOrderedPaire[i].index.back() << " | " ;
    // }
    // std::cout << "\n";
    // print(v_largeNums);
    // print(v_smallOrderedPaire);
    // std::cout << "=======================================================\n" ;
}

std::vector<Int>::iterator findIndex(std::vector<Int>& v_largeNums, std::vector<Int>& v_mainChain, Int& v_smallOrderedPaire)
{
    int index = v_smallOrderedPaire.index.back();
    std::vector<Int>::iterator it = std::find(v_largeNums.begin(), v_largeNums.end(), v_largeNums[index]);
    if ( it == v_largeNums.end() )
        it  = v_mainChain.end();
    return it;

}
void PmergeMe::insertion(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums)
{
    std::vector<Int> v_mainChain;
    std::vector<Int> v_smallOrderedPaire;

    orderedThePair(v_largeNums, v_smallNums, v_smallOrderedPaire);

    v_mainChain.push_back(v_smallOrderedPaire[0]);

    std::vector<int> jacob = JacobSequenceIndexes(v_largeNums.size());

    // std::cout << "++++++++++++++++jacob_sequence+++++++++++++++++\n";

    // for (size_t i = 0; i < jacob.size(); i++)
    // {
    //     std::cout << jacob[i] << ", ";
    // }
    // std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++\n";

    int prevJacob = 0; 

    for (int i = 0; i < (int)jacob.size(); i++)
    {
        int curr = jacob[i];
        if (curr >= (int)v_smallOrderedPaire.size())
            curr = (int)v_smallOrderedPaire.size() - 1;

        for (int j = prevJacob; j < curr; j++)
            v_mainChain.push_back(v_largeNums[j]);

        // Walk backwards inserting b's with lower_bound up to paired a
        for (int j = curr ; j > prevJacob; j--)
        {
            if (j == 0)
                continue;
            if (j >= (int)v_smallOrderedPaire.size())
                continue;
            // std::vector<Int>::iterator upper = findIndex(v_largeNums, v_mainChain, v_smallOrderedPaire[j]);
            std::vector<Int>::iterator it = std::lower_bound(
                v_mainChain.begin(), v_mainChain.end(), v_smallOrderedPaire[j]);
            v_mainChain.insert(it, v_smallOrderedPaire[j]);
        }
        prevJacob = curr;
    }

    // Push remaining a's FREE (not covered by jacob)
    for (int j = prevJacob; j < (int)v_largeNums.size(); j++)
        v_mainChain.push_back(v_largeNums[j]);

    // Insert remaining b's
    for (int j = prevJacob + 1; j < (int)v_smallOrderedPaire.size(); j++)
    {
        if (j == 0)
            continue;

        std::vector<Int>::iterator it = std::lower_bound(
            v_mainChain.begin(), v_mainChain.end(), v_smallOrderedPaire[j]);
        v_mainChain.insert(it, v_smallOrderedPaire[j]);
    }

    v_largeNums.clear();
    v_largeNums = v_mainChain;
}

// static int lvl;
void PmergeMe::algorithm(std::vector<Int>& v_largeNums)
{
    std::vector<Int> v_smallNums;
    
    if (v_largeNums.size() == 1)
        return;

    PairwiseComparison(v_largeNums, v_smallNums);
    mapThePairs(v_largeNums, v_smallNums);

    algorithm(v_largeNums);

    insertion(v_largeNums, v_smallNums);
    for (size_t i = 0; i < v_largeNums.size(); i++)
    {
        if (!v_largeNums[i].index.empty())
            v_largeNums[i].index.pop_back();
    }
}



// Initialize the timer
void PmergeMe::initTime()
{
    _g_startTime = clock();
}

double PmergeMe::timeOfSorting()
{
    clock_t endTime = clock();
    double time = double(endTime - _g_startTime) / CLOCKS_PER_SEC * 1000.0;
    return time;
}

std::vector<Int>& PmergeMe::getVectorNums()
{
    return _v_nums;
}

void PmergeMe::setNums(std::vector<Int>& v_args)
{
    _v_nums = v_args;
}

std::ostream& operator<<(std::ostream& os, Int& obj)
{
    os << obj.value;
    return os;
}

