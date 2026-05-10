#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <utility>

// using namespace std;

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


};

std::ostream&    operator<<(std::ostream& os, Int& obj);


class PmergeMe {

    std::vector<Int> v_nums;
    
    // PmergeMe();
    void    PairwiseComparison(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums);
    void    insertion(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums);
    void    orderedThePair(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums, std::vector<Int>& v_orderedPaire);
    void    mapThePairs(std::vector<Int>& v_largeNums, std::vector<Int>& v_smallNums);


    public:
        PmergeMe(std::vector<std::string> v_str);
        PmergeMe();
        void    algorithm(std::vector<Int>& v_largeNums);
        void sort();
        void setNums(std::vector<Int>& v_args);
        std::vector<Int>& getnums();
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