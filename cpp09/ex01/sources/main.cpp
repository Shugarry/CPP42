#include "../headers/RPN.hpp"

#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "wrong input. format: ./poland \"<operation>\"";
		return 1;
	}
	RPN rpn;
	try
	{
		rpn.process_input(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}
}
