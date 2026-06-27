#include "RNP.hpp"

Rnp::Rnp(void)
{
	_length = 0;
	_result = 0;
}

Rnp::~Rnp(void)
{

}

Rnp::Rnp(const Rnp &src)
{
	*this = src;
}

Rnp	&Rnp::operator=(const Rnp &src)
{
	if (this != &src)
	{
		_length = src._length;
		_result = src._result;
		_stack = src._stack;
	}
	return (*this);
}


void	check_input(char *argv)
{
	std::string	input = argv;

	for (size_t i = 0; i < input.length(); i++)
	{
		if ((input[i] < 48 || input[i] > 57) && (input[i] != '*' && input[i] != '+' && input[i] != '/' && input[i] != '-' && input[i] != ' '))
			throw std::runtime_error("Error: bad input: should only contain numbers (integers)");
	}

	for (size_t i = 0; i < input.length(); i++)
	{
		if ((input[i] >= '0' && input[i]))
		{
			if (i + 1 < input.length() && (input[i + 1] != ' '))
				throw std::runtime_error("Error: bad input: should only conatin number between 0 and 9 and with spaces between each number / operator");
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			if (i + 1 < input.length() && (input[i + 1] != ' '))
				throw std::runtime_error("Error: bad input: should only conatin number between 0 and 9 and with spaces between each number / operator");
		}
		else
			continue;
	}
}

void	Rnp::calculate(std::string	input)
{
	_length = input.length();

	for (size_t i = 0; i < _length; i++)
	{
		if (input[i] == ' ')
			continue;
		if (input[i] >= '0' && input[i] <= '9')
			_stack.push(input[i] - '0');
		else
		{
			if (_stack.empty())
			{
				throw std::runtime_error("Error: can't apply an operation on zero element");
				return ;
			}
			int a = _stack.top();
			_stack.pop();
			if (_stack.empty())
			{
				throw std::runtime_error("Error: can't apply an operation on one element only");
				return ;
			}
			int b = _stack.top();
			_stack.pop();
			_result = op(b, input[i], a);
			_stack.push(_result);
		}
	}
	std::cout << std::fixed << std::setprecision(2) << _stack.top() << std::endl;
}

float	Rnp::op(int a, char oper, int b)
{
	switch (oper)
	{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '/':
		{
			if (b == 0)
				throw std::runtime_error("Error: division by 0 is impossible ");
			return static_cast<float>(a) / static_cast<float>(b);
			break;
		}
		case '*':
			return a * b;
			break;
		default:
			std::cout << std::endl;
			return (0);
	}
}
