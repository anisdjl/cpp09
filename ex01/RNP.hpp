#ifndef RNP_HPP
# define RNP_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

class Rnp
{
	private:
		std::stack<float>		_stack;
		size_t					_length;
		float					_result;

	public:
		Rnp(void);
		~Rnp(void);
		Rnp(const Rnp &src);
		Rnp &operator=(const Rnp &src);
		void	calculate(std::string input);
		float	op(int a, char oper, int b);
};

void	check_input(char *argv);

#endif