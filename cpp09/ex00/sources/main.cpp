#include "../headers/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "wrong input. method: ./bitcoin <file>\n";
		return 1;
	}
	BitcoinExchange data;
	try
	{
		data.parse_database("data.csv");
		data.parse_file(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}
}
