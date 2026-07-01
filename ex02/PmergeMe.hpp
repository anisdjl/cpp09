#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>

typedef struct s_block
{
	std::vector<int>	numbers;
	int					great_elem;
}	v_block;

typedef struct s_struct
{
	std::deque<int>		numbers;
	int					great_elem;
}	dq_block;

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_dqueue;

	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		void	check_input(char **argv, int argc);
		void	sort_algo_vect(int pairs_size);
		void	sort_algo_dq(int pairs_size);
		void	up_recur_vect(int pairs_size);
		void	up_recur_dq(void);
};


#endif