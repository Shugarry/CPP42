#include "../headers/Data.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "wrong input. method: ./bitcoin <file>\n";
		return 1;
	}

	Data historic_data(av[1]);
}
