#include "BitcoinExchange.hpp"

// void	fill_the_data(std::ifstream &infile)
// {
// 	std::string line;
// 	int i = 0;

// 	while (getline(infile, line))
// 	{
// 		std::cout << line << std::endl;
// 		check_date(line);
// 		check_price(line);
// 		i++;
// 	}
// 	std::cout << i << std::endl;
// 	return ;
// }

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

// je dois lire la data base donne dans le .csv, stocker tout ca dans un std::map
// le std::map permet d'avoir des cle (les dates) et les valeurs (le prix du bitcoin)
// je dois avoir un check pour le format de la map yyyy-mm-dd
// je dois avoir un check pour les valeurs du birtcoin, elles doivent etre en float ou en int et doivent etre entre 0 et 1000 sinon c'est faux
// je sais pas si je dois checker avant de remplir ou bien remplir et ensuite checker donc peut etre plus simple, ou bien checker en remplissant (je pense checker en remplissant)
// je dois checker si le format du file est bien : date | value