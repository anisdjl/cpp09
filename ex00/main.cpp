#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: try with './btc filename'" << std::endl;
		return (1);
	}
	try
	{
		Bitcoin test;
		test.data_processing(argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
