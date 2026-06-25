#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void)
{
	_value = 0;
	_month = 0;
	_day = 0;
	_year = 0;
	fill_data();
}

Bitcoin::~Bitcoin(void)
{

}

Bitcoin::Bitcoin(const Bitcoin &src) : _bitcoin(src._bitcoin), _value(src._value), _date(src._date), _month(src._month), _day(src._day), _year(src._year)
{

}

Bitcoin	&Bitcoin::operator=(const Bitcoin &src)
{
	if (this != &src)
	{
		_value = src._value;
		_bitcoin = src._bitcoin;
		_day = src._day;
		_month = src._month;
		_year = src._year;
		_date = src._date;
	}
	return (*this);
}

void	Bitcoin::fill_data(void)
{
	std::string line;
	std::ifstream infile("data.csv");
	std::string	date;
	std::string price;
	float float_price;
	size_t find_comma;

	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file data.csv");
	
	getline(infile, line);
	while (getline(infile, line))
	{
		find_comma = line.find(',');
		if (find_comma == std::string::npos)
			continue;
		price = line.substr(find_comma + 1);
		date = line.substr(0, find_comma);
		std::stringstream ss(price);
		ss >> float_price;

		_bitcoin.insert(std::make_pair(date, float_price));
	}
	infile.close();
}

void	Bitcoin::data_processing(char **argv)
{
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		throw std::runtime_error("Error: could not open the input file");
	}

	std::string	input;
	size_t		delimiter;
	std::getline(infile, input);
	while (getline(infile, input))
	{
		delimiter = input.find('|');
		if (delimiter == std::string::npos)
		{
			std::cout << "Error: bad input => " << input << std::endl;
			continue;
		}
		std::string clean_date;
		std::string date = input.substr(0, delimiter);
		std::stringstream ss(date);
		ss >> clean_date;
		if (!date_check(clean_date))
			continue;
		if (!value_check(input))
			continue;
		display_result();
	}
	infile.close();
}

void	Bitcoin::display_result(void)
{
	std::map<std::string, float>::const_iterator it = _bitcoin.lower_bound(_date);

	if (it != _bitcoin.end() && it->first == _date)
	{
		std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;
		return ;
	}
	else
	{
		if (it == _bitcoin.begin())
		{
			std::cout << "Error: no database entry before this date => " << _date << std::endl;
			return ;
		}
		--it;
		std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;
		return ;
	}
	return ;
}

bool	Bitcoin::date_check(std::string &str)
{
	std::string	year;
	std::string	month;
	std::string	day;

	_date = str;
	if (str.length() < 10)
		return (false);
	if (str[4] != '-' || str[7] != '-')
		return (false);
	
	year = str.substr(0, 4);
	month = str.substr(5, 2);
	day = str.substr(8, 2);

	for (int i = 0; i < 4; i++)
	{
		if (year[i] < 48 || year[i] > 57)
			return (false);
	}
	for (int i = 0; i < 2; i++)
	{
		if (month[i] < 48 || month[i] > 57)
			return (false);
	}
	for (int i = 0; i < 2; i++)
	{
		if (day[i] < 48 || day[i] > 57)
			return (false);
	}

	std::stringstream	y(year);
	std::stringstream	m(month);
	std::stringstream	d(day);

	y >> _year;
	m >> _month;
	d >> _day;

	if (_month > 12 || _month < 1)
	{
		std::cout << "Error: invalid month" << std::endl;
		return (false);
	}
	int	dayPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
		dayPerMonth[2] = 29;
	
	if (_day < 1 || _day > dayPerMonth[_month])
	{
		std::cout << "Error: invalid day of the month" << std::endl;
		return (false);
	}
	return (true);
}

bool	Bitcoin::value_check(std::string &str)
{
	std::string	value;
	value = str.substr(str.find('|') + 1);
	std::stringstream	ss(value);
	
	ss >> _value;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: bad value" << std::endl;
		return (false);
	}
	if (_value > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return (false);
	}
	else if (_value < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return (false);
	}
	return (true);
}
