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

void Data::parse_file(std::string filename)
{
	this->filename = filename;
	std::ifstream file(filename);
	if (file.is_open() == false)
		throw std::runtime_error("Error: could not open file");
	std::string stream;

	while (std::getline(file, stream))
	{

	}
}
