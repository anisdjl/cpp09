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
		std::cout << price << std::endl;
		date = line.substr(0, find_comma);
		std::cout << date << std::endl;
		std::cout << line << std::endl;
		std::stringstream ss(price);
		ss >> float_price;

		_bitcoin.insert(std::make_pair(date, float_price));
	}
	// for (auto x : _bitcoin)
	// 	std::cout << "date " << x.first << " price " << std::fixed << std::setprecision(100) << x.second << std::endl;
}