#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return 0;
	}

	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				std::cout << (char)(av[i][j] - ('a' - 'A'));
			else
				std::cout << av[i][j];
		}
	}
	std::cout << "\n";

	return 0;
}
