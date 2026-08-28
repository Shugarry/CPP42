#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void parse_file(std::string filename);
		void parse_database(std::string filename);
		double find_closest_value(time_t epoch);
		void print_conversion(std::string date, double value, time_t epoch);
		void print();

	private:
		std::map<time_t, double> map;
};

#endif
