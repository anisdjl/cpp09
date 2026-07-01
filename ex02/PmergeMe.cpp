#include "PmergeMe.hpp"

static bool	compare(const v_block &a, const v_block &b)
{
	return (a.great_elem < b.great_elem);
}
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
		_vector = src._vector;
		_dqueue = src._dqueue;
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
	// std::cout << "==== vect Before recurcive ====" << std::endl;
	// for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }
	sort_algo_vect(1);
	// std::cout << "==== vect After recurcive ====" << std::endl;
	// for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }

	// std::cout << "==== vector after sort ====" << std::endl;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

// 	std::cout << std::endl;
// 	std::cout << "==== dqueue Before recurcive ====" << std::endl;
// 	for (std::deque<int>::const_iterator it = _dqueue.begin(); it != _dqueue.end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
// 	sort_algo_dq(1);
// 	std::cout << "==== dqueue After recursive ====" << std::endl;
// 	for (std::deque<int>::const_iterator it = _dqueue.begin(); it != _dqueue.end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
}

void	PmergeMe::sort_algo_vect(int pairs_size)
{
	if (static_cast<size_t>(2 * pairs_size) > _vector.size()) // si je n'ai pas assez de chiffre pour faire des paires de taille de size pairs je return (fin de la recur)
		return ;

	for (size_t i = 0; i + 2 * pairs_size <= _vector.size(); i += 2 * pairs_size) // on commence a 0 et tant que i + 2 * pair_siz est inf a la taille du vect on va faire et on incremente de deux car on travaille avec des pairs 
	{
		if (_vector[i + pairs_size - 1] > _vector[i + 2 * pairs_size - 1])
		{
			for (int k = 0; k < pairs_size; ++k)
				std::swap(_vector[i + k], _vector[i + pairs_size + k]);
		}
	}
	sort_algo_vect(pairs_size * 2);
	up_recur_vect(pairs_size);
}


// void	PmergeMe::sort_algo_dq(int pairs_size)
// {
// 	if (static_cast<size_t>(pairs_size * 2) > _dqueue.size())
// 		return ;

// 	for (size_t i = 0; i + 2 * pairs_size <= _dqueue.size(); i += 2 * pairs_size)
// 	{
// 		if (_dqueue[i + pairs_size - 1] > _dqueue[i + 2 * pairs_size - 1])
// 		{
// 			for (int k = 0; k < pairs_size; ++k)
// 				std::swap(_dqueue[k + i], _dqueue[k + pairs_size + i]);
// 		}
// 	}
// 	sort_algo_dq(pairs_size * 2);
// }

void	PmergeMe::up_recur_vect(int pairs_size)
{
	bool	odd_num_elem = false;
	v_block	odd_block;
	size_t size_odd = (_vector.size() / pairs_size) * pairs_size;
	
	if (_vector.size() % pairs_size != 0)
	{
		odd_num_elem = true;
		for (size_t i = size_odd; i < _vector.size(); ++i)
			odd_block.numbers.push_back(_vector[i]);

		odd_block.great_elem = _vector[_vector.size() - 1];
	}

	std::vector<v_block> block;

	for (size_t i = 0; i + pairs_size <= size_odd; i += pairs_size)
	{
		v_block tmp_block;
		for (size_t y = i; y < i + pairs_size; y++)
			tmp_block.numbers.push_back(_vector[y]);
		tmp_block.great_elem = _vector[i + pairs_size - 1];
		block.push_back(tmp_block);
	}

	std::vector<v_block>	main_chain;
	std::vector<v_block>	pend;

	for (size_t a = 0; a < block.size(); ++a)
	{
		if (a % 2 == 0)
			pend.push_back(block[a]);
		else
			main_chain.push_back(block[a]);
	}
	if (!pend.empty())
		main_chain.insert(main_chain.begin(), pend[0]);

	size_t	curr_step = 3; // c'est le prochaine position du chiffre qu'on doit mettre dans la main chain
	size_t	prev_step = 1; // 1 au debut pcq on a deja mis le chiffre a l'index 0 dans la main chain

	while (prev_step < pend.size())
	{
		size_t	upper_bound = curr_step - 1; // c'est l'index auquel on commence

		if (upper_bound >= pend.size())
			upper_bound = pend.size() - 1;

		size_t	lower_bound = prev_step - 1; // l'index auquel on termine le -1 c'est pour le decalage de l'index

		for (size_t s = upper_bound; s > lower_bound; --s)
		{
			v_block target;

			target.great_elem = pend[s].great_elem;

			std::vector<v_block>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), target, compare);
			main_chain.insert(it, pend[s]);
		}

		size_t	next_step = curr_step + 2 * prev_step;
		prev_step = curr_step;
		curr_step = next_step;
	}

	if (odd_num_elem)
	{
		std::vector<v_block>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), odd_block, compare);
		main_chain.insert(it, odd_block);
	}

	_vector.clear();
	for (size_t l = 0; l < main_chain.size(); ++l)
	{
		for (size_t j = 0; j < main_chain[l].numbers.size(); ++j)
			_vector.push_back(main_chain[l].numbers[j]);
	}
}

// void	PmergeMe::up_recur_dq(void)
// {

// }