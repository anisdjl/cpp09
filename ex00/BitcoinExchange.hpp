#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

class Bitcoin
{
	private:
		std::map<std::string, float> _bitcoin;

	public:
		Bitcoin(void);
		~Bitcoin(void);
		Bitcoin(const Bitcoin &src);
		Bitcoin 		&operator=(const Bitcoin &src);
		void			fill_data(void);
		void			data_processing(char **argv);
		void			display_result(void);
		bool			date_check(std::string &str);
		bool			value_check(std::string &str);
};


#endif