#include "../headers/ScalarConverter.hpp"
# include <iostream>
# include <limits>
# include <cstdlib>
# include <cctype>

ScalarConverter::ScalarConverter()
{
};

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
};

ScalarConverter::~ScalarConverter()
{
};

void is_char(std::string parameter)
{
	char c = parameter[1];

	std::cout << "char: " << c << "\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void is_number(std::string parameter)
{
	char* end;
	double d = std::strtod(parameter.c_str(), &end);

	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
	{
		std::cout << "char: invalid literal\n";
		std::cout << "int: invalid literal\n";
		std::cout << "float: invalid literal\n";
		std::cout << "double: invalid literal\n";
		return;
	}
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
	std::string float_str = "conversion not possible";
	std::string double_str = "conversion not possible";

	if (parameter == "nanf" || parameter == "-inff" || parameter == "+inff")
	{
		float_str = parameter;
		double_str = parameter.substr(0, parameter.length() - 1);
		std::cout << "char: conversion not possible" << "\n";
		std::cout << "int: conversion not possible" << "\n";
		std::cout << "float: " << float_str << "\n";
		std::cout << "double: " << double_str << "\n";
	}
	else if (parameter == "nan" || parameter == "-inf" || parameter == "+inf")
	{
		float_str = parameter + "f";
		double_str = parameter;
		std::cout << "char: conversion not possible" << "\n";
		std::cout << "int: conversion not possible" << "\n";
		std::cout << "float: " << float_str << "\n";
		std::cout << "double: " << double_str << "\n";
	}
	else if (parameter.length() == 3 && parameter[0] == '\'' && parameter[2] == '\'')
		is_char(parameter);
	else if (parameter.length() == 1 && !std::isdigit(parameter[0]))
		is_char("'" + parameter + "'");
	else
		is_number(parameter);
}
