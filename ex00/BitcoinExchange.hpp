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
		Bitcoin &operator=(const Bitcoin &src);
		void	fill_data(void);
};

void	fill_the_data(std::ifstream &infile);

#endif