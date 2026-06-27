#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

void	check_input(char **argv, int argc)
{
	//long long	value;

	for (int i = 1; i < argc; i++)
	{
		std::string	input = argv[i];
		for (size_t i = 0; i < input.length(); i++) // est ce qu'on doit gere les +2323 etc...
		{
			if (!(input[i] >= '0' && input[i] <= '9'))
				throw std::runtime_error("Error: bad input: enter only integers");
		}
	}

	for (int i = 1; i < argc; i++)
	{
		long long value;
		std::stringstream ss(argv[i]);

		ss >> value;
		if (ss.fail() || !ss.eof())
			throw std::runtime_error("Error: bad input: enter only integers");
		if (value > INT_MAX)
			throw std::runtime_error("Error: bad input: you must enter only a number between INT_MIN and INT_MAX");
		
		// ici je vais commencer a remplir mes containers il faut que je check si je dois prendre ne compte les " et les '
	}
}