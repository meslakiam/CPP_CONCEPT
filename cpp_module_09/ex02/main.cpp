#include "PmergeMe.hpp"

void	printResulte(std::deque<Int>& _dq_nums, std::string str)
{
	std::cout << str << ": " ;
	for (size_t i = 0; i < _dq_nums.size(); i++)
	{
		std::cout << _dq_nums[i] << " " ;
	}
	std::cout << std::endl;
	
}

void	printResulte(std::vector<Int>& _v_nums, std::string str)
{
	std::cout << str << ": " ;
	for (size_t i = 0; i < _v_nums.size(); i++)
	{
		std::cout << _v_nums[i] << " " ;
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
		std::deque<std::string> dq_args(v_args.begin(), v_args.end());

		std::cout << "\n==================================================\n";
        PmergeMe	v_algo(v_args);
	
		printResulte(v_algo.getVectorNums(), "vector befor");
		v_algo.initTime();

        v_algo.sort(v_algo.getVectorNums());
	
		printResulte(v_algo.getVectorNums(), "vector after");
		std::cout << "time of sorting a vector = " << v_algo.timeOfSorting() << "ms\n";

		std::cout << "\n==================================================\n\n";

		std::cout << "\n==================================================\n";
		PmergeMe	dq_algo(dq_args);

		v_algo.initTime();

		printResulte(dq_algo.getDequeNums(), "deque befor");

		dq_algo.sort(dq_algo.getDequeNums());

		printResulte(dq_algo.getDequeNums(), "deque after");
		std::cout << "time of sorting a deque = " << v_algo.timeOfSorting() << "ms\n";
		std::cout << "\n==================================================\n";
 
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error:\n" <<  e.what() << std::endl;
    }

    return 0;
}
