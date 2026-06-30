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

void	PmergeMe::check_input(char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	input = argv[i];
		for (size_t i = 0; i < input.length(); i++)
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
		_vector.push_back(value);
		_dqueue.push_back(value);	
	}
	// for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// std::cout << std::endl;
	// for (std::deque<int>::const_iterator it = _dqueue.begin(); it != _dqueue.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }
}

void	PmergeMe::sort_algo_vect(int pairs_size)
{
	if (static_cast<size_t>(2 * pairs_size) > _vector.size()) // si je n'ai pas assez de chiffre pour faire des paires de taille de size pairs je return (fin de la recur)
		return ;

	std::cout << "======== " << pairs_size << " ======" << std::endl;
	for (size_t i = 0; i + 2 * pairs_size < _vector.size(); i += 2 * pairs_size) // on commence a 0 et tant que i + 2 * pair_siz est inf a la taille du vect on va faire et on incremente de deux car on travaille avec des pairs 
	{
		std::cout << "left : " << _vector[i + pairs_size - 1] << " right : " << _vector[i + 2 * pairs_size - 1] << " => : [" << _vector[i + pairs_size - 1] << ", " << _vector[i + 2 * pairs_size - 1] << "]" << std::endl;
	}
	// std::cout << pairs_size << std::endl;
	sort_algo_vect(pairs_size * 2);

}


// void	PmergeMe::sort_algo_dq(void)
// {

// }
