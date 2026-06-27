#include "RNP.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: try with this input: ./RNP \" formula \"" << std::endl;
		return (1);
	}
	try
	{
		check_input(argv[1]);
		std::string	input = argv[1];
		Rnp my_rnp;
		my_rnp.calculate(input);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

// je dois parser et m'assurer que ca ne soit pas des decimals et que ca ne contiennt que des chiffres ou des +-/*
// 