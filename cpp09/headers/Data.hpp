#ifndef DATA_HPP
# define DATA_HPP

#include "Bitcoin.hpp"
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

class Data
{
	public:
		Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();

		Data(std::string filename);

		void parse_file(std::string filename);

	private:
		std::string filename;
		std::map<time_t, Bitcoin> value_db;
};

#endif
