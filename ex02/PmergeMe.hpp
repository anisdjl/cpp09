#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>

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
		void	sort_algo_vect(void);
		void	sort_algo_dq(void);
};


#endif