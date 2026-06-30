#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: you must at least enter a number" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pm;
		pm.check_input(argv, argc);
		pm.sort_algo_vect(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}