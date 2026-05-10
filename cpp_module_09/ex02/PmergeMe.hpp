#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cerrno>
#include <utility>
#include <vector>
#include <deque>

struct Int
{
    Int(int val): value(val)
    {}

    std::vector<int> index;
    int value;
    static int Count;
    Int(const Int& other)
    {
        this->value = other.value;
        this->index = other.index;
        
    }
    Int&    operator=(const Int& other)
    {
        if ( this == &other )
            return *this;

        this->value = other.value;
        this->index = other.index;
        return *this;
    } 
    bool operator<(const Int& i)
    {
        Count++;
        return value < i.value;
    }
    bool operator==(const Int& i)
    {
        return value == i.value;
    }

};

std::ostream&    operator<<(std::ostream& os, Int& obj);


class PmergeMe {

    std::vector<Int> v_nums;
    std::deque<Int>  dq_nums;
    static clock_t g_startTime;

    std::vector<int> JacobSequenceIndexes(size_t size);
    void    PairwiseComparison(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums);
    void    insertion(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums);
    void    orderedThePair(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums, std::vector<Int>& v_orderedPaire);
    void    mapThePairs(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums);


    void    PairwiseComparison(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums);
    void    mapThePairs(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums);
    void    orderedThePair(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums, std::deque<Int>& dq_smallOrderedPaire);
    void    insertion(std::deque<Int>& dq_largeNums, std::deque<Int>& dq_smallNums);

    public:
        PmergeMe(std::vector<std::string> v_str);
        PmergeMe(std::deque<std::string>  dq_str);
        PmergeMe();
    
        void    algorithm(std::vector<Int>& v_largeNums);
        void    sort(std::vector<Int>& v_nums);
        void    setNums(std::vector<Int>& v_args);
        std::vector<Int>& getVectorNums();

        void    algorithm(std::deque<Int>& dq_largeNums);
        void    sort(std::deque<Int>&  dq_nums);
        void    setNums(std::deque<Int>& dq_args);
        std::deque<Int>& getDequeNums();

        void    initTime();
        double  timeOfSorting();
};


struct HasSameIndex
{
    int target;
    
    HasSameIndex(int i) : target(i)
    {}

    bool    operator()(const Int& obj ) const
    {
        return ( ( !(obj.index.empty() ) && (obj.index.back() == target) ) ) ;
    }

};