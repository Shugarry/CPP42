#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): map()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): map(other.map)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		map = other.map;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

// format YYYY-MM-DD
static bool valid_date(std::string& date)
{
	if (date.size() != 10)
		return false;

	unsigned int day = atoi(date.substr(8, 9).c_str());
	unsigned int month = atoi(date.substr(5, 6).c_str());
	unsigned int year = atoi(date.substr(0, 4).c_str());

	if (day < 1 || month < 1 || month > 12)
		return false;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
			return false;
	}
	else if (month == 2)
	{
		if (day == 29 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return false;
		else if (day > 29)
			return false;
	}
	else
	{
		if (day > 30)
			return false;
	}
	return true;
}

static time_t date_to_epoch(std::string date_str)
{
	struct tm tm = {};
	time_t epoch;
	if (strptime(date_str.c_str(), "%Y-%m-%d", &tm) == NULL)
		throw std::runtime_error("Error: strptime() failure");
	epoch = timegm(&tm);
	return epoch;
}

void BitcoinExchange::print_conversion(std::string date, double value, time_t epoch)
{
	double exchange_rate = find_closest_value(epoch);
	std::cout << date << " => " << value << " = " << value * exchange_rate << "\n";
}

void BitcoinExchange::print()
{
	std::cout << "DATABASE SIZE: " << map.size() << "\n";
	for (std::map<time_t, double>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << "date: " << it->first << " | value: " << it->second << "\n";
}

void BitcoinExchange::parse_database(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (file.is_open() == false)
		throw std::runtime_error("Error: could not open file");
	
	std::string stream;
	std::getline(file, stream);
	while (std::getline(file, stream))
	{
		std::string date = stream.substr(0, stream.find(","));
		std::string exchange_rate_str = stream.substr(stream.find(",") + 1, std::string::npos);
		double exchange_rate = std::atof(exchange_rate_str.c_str());

		map.insert(std::pair<time_t, double>(date_to_epoch(date), exchange_rate));
	}
}

void BitcoinExchange::parse_file(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (file.is_open() == false)
		throw std::runtime_error("Error: could not open file");
	
	std::string stream;
	std::getline(file, stream);
	if (stream.find("date") == std::string::npos || stream.find("value") == std::string::npos)
	{
		throw std::runtime_error("Error: wrongly formatted input file");
		file.close();
	}

	std::string separator = stream.substr(stream.find("date") + 4, stream.find("value") - 4);
	while (std::getline(file, stream))
	{
		std::string date = stream.substr(0, stream.find(separator));
		std::string value_str = stream.substr(stream.find(separator) + separator.size(), std::string::npos);
		if (valid_date(date) == false)
		{
			std::cout << "Error: bad input => " << date << "\n";
			continue ;
		}
		
		double value = std::atof(value_str.c_str());
		if (value < 0 || value > 1000)
		{
			std::cout << "Error: value out of range\n";
			continue ;
		}
		if (!isdigit(*value_str.begin()))
		{
			std::cout << "Error: not a number\n";
			continue ;
		}
		print_conversion(date, value, date_to_epoch(date));
	}
}

double BitcoinExchange::find_closest_value(time_t epoch)
{
	std::map<time_t, double>::iterator it, it_prev;

	it = map.lower_bound(epoch);
	if (it == map.end())
		return map.rbegin()->second;
	else if (it == map.begin())
		return it->second;
	else
	{
		it_prev = it;
		it_prev--;
		if (epoch - it_prev->first < it->first - epoch)
			return it_prev->second;
		else
			return it->second;
	}
}
