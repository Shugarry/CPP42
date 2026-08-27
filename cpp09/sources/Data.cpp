#include "../headers/Data.hpp"

Data::Data(): filename(), value_db()
{
}

Data::Data(const Data& other): filename(other.filename), value_db(other.value_db)
{
}

Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		filename = other.filename;
		value_db = other.value_db;
	}	
	return *this;
}

Data::~Data()
{
}

Data::Data(std::string filename): filename(filename)
{
	parse_file(filename);
}

// format YYYY-MM-DD
static bool valid_date(std::string& date)
{
	if (date.size() != 10)
		return false;

	unsigned int day = atoi(date.substr(8, 9).c_str());
	unsigned int month = atoi(date.substr(5, 6).c_str());
	unsigned int year = atoi(date.substr(0, 3).c_str());
	
	if (year < 0 || year > 2026)
		return false;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
			return false;
	}
	else if (month == 2)
	{
		if (day == 29 && !(year % 4 == 0 && year % 100 != 100))
			return false;
		else if (day > 28)
			return false;
	}
	else
	{
		if (day > 30)
			return false;
	}
	return true;
}

void Data::print()
{
	for (std::map<time_t, double>::iterator it = value_db.begin(); it != value_db.begin(); it++)
		std::cout << "" << it->first << "";
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

void Data::parse_file(std::string filename)
{
	this->filename = filename;
	std::ifstream file(filename);
	if (file.is_open() == false)
		throw std::runtime_error("Error: could not open file");
	
	std::string stream;
	std::getline(file, stream);
	if (stream.find("date") == std::string::npos || stream.find("value") == std::string::npos)
		throw std::runtime_error("wrongly formatted input file");

	std::string separator = stream.substr(stream.find("date"), stream.find("value"));
	while (std::getline(file, stream))
	{
		std::string date = stream.substr(0, stream.find(separator));
		std::string value_str = stream.substr(stream.find(separator), std::string::npos);
		if (valid_date(date) == false)
		{
			std::cout << "Error: bad input => " << date;
			continue ;
		}
		
		double value = std::stof(date.c_str());
		if ((value < 0 || value > 1000) && filename != "data.csv")
		{
			std::cout << "Error: value out of range" << date;
			continue ;
		}
		if (!isdigit(value_str.front()) && filename != "data.csv")
		{
			std::cout << "Error: not a number" << date;
			continue ;
		}
		value_db.insert({date_to_epoch(date), value});
	}
}
