#include "../headers/Data.hpp"

time_t date_to_epoch(std::string date_str)
{
	struct tm tm = {};
	time_t epoch;
	if (strptime(date_str.c_str(), "%Y-%m-%d", &tm) == NULL)
		throw std::runtime_error("Error: strptime() failure");
	epoch = timegm(&tm);
	return epoch;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "wrong input. method: ./bitcoin <file>\n";
		return 1;
	}

	Data historic_data(av[1]);
}
