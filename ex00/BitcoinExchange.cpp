#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void)
{
	fill_data();
}

Bitcoin::~Bitcoin(void)
{

}

// Bitcoin::Bitcoin(const Bitcoin &src)
// {

// }

void	Bitcoin::fill_data(void)
{
	std::string line;
	std::ifstream infile("data.csv");
	std::string	date;
	std::string price;
	float float_price;
	size_t find_comma;

	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file data.csv\n");
	
	getline(infile, line);
	while (getline(infile, line))
	{
		find_comma = line.find(',');
		if (find_comma == std::string::npos)
			continue;
		price = line.substr(find_comma + 1);
		// std::cout << price << std::endl;
		date = line.substr(0, find_comma);
		// std::cout << date << std::endl;
		// std::cout << line << std::endl;
		std::stringstream ss(price);
		ss >> float_price;

		_bitcoin.insert(std::make_pair(date, float_price));
	}
	for (std::map<std::string, float>::const_iterator it = _bitcoin.begin(); it != _bitcoin.end(); ++it)
		std::cout << "date " << it->first << " price " << it->second << std::endl;
}

void	Bitcoin::data_processing(char **argv)
{
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		throw std::runtime_error("Error: could not open the input file");
	}

	std::string	input;
	std::getline(infile, input);

	while (getline(infile, input))
	{
		if (!value_check)
			// affiche l'erreur de la valeur
			continue;
		if (!date_check)
			// affiche l'erreur de la date
			continue;
		if (date_check(input) && value_check(input))
			// cherche dans la db
			continue;
	}
}