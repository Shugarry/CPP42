#include "../headers/Harl.hpp"
#include <iostream>

void Harl::debug()
{
	std::cout << "DEBUG: MY VERY CREATIVE DEBUG MESSAGE" << std::endl;
}

void Harl::info()
{
	std::cout << "INFO: ANOTHER EXAMPLE OF MY BOUNDLESS CREATIVITY" << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING: CREATIVITY REACHING CRITICAL MASS" << std::endl;
}

void Harl::error()
{
	std::cout << "ERROR: YOU \"CREATIVED\" TO CLOSE TO THE SUN. ITS OVER" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Level does not exist" << std::endl;
}
