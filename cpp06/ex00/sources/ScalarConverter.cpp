#include "../headers/ScalarConverter.hpp"
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
};

void is_char(std::string parameter)
{
	char c = parameter[1];

	std::cout << "char: " << c << "\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void is_int(std::string parameter)
{
	int i = std::stoi(parameter);

	std::cout << "char: " << i << "\n";
	std::cout << "int: " << static_cast<int>(i) << "\n";
	std::cout << "float: " << static_cast<float>(i) << "\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void is_decimal(std::string parameter)
{
	double d = std::strtod(parameter.c_str(), NULL);

	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
		std::cout << "char: conversion not possible\n";
	else
	{
		if (std::isprint(static_cast<char>(d)))
			std::cout << "char: " << static_cast<char>(d) << "\n";
		else
			std::cout << "char: character is non printable\n";
	}
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: conversion not possible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";
	std::cout << "float: " << static_cast<float>(d) << "\n";
	std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(std::string parameter)
{
	std::string char_str = "conversion not possible";
	std::string int_str = "conversion not possible";
	std::string float_str = "conversion not possible";
	std::string double_str = "conversion not possible";

	if (parameter == "nanf" || parameter == "-inff" || parameter == "+inff" )
	{
		float_str = parameter;
		double_str = parameter.substr(0, parameter.length() - 1);
	}
	else if (parameter == "nan" || parameter == "-inf" || parameter == "+inf" )
	{
		float_str = parameter + "f";
		double_str = parameter;
	}
	else if (parameter.length() == 3 && parameter[0] == '\'' && parameter[2] == '\'')
	{
		is_char(parameter);
		return ;
	}
	else if (parameter.find('.') != std::string::npos)
	{
		is_decimal(parameter);
		return ;
	}
	std::cout << "char: " << char_str << "\n";
	std::cout << "int: " << int_str << "\n";
	std::cout << "float: " << float_str << "\n";
	std::cout << "double: " << double_str << "\n";
}
