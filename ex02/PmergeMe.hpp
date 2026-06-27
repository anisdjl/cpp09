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
	
	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
};

void	check_input(char **argv, int argc);

#endif