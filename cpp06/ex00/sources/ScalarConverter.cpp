#include "../headers/ScalarConverter.hpp"
#include <iostream>

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
}

void is_int(std::string parameter)
{
	int value = std::stoi(parameter);
}

void is_float(std::string parameter)
{
	float value = std::stof(parameter);
}

void is_double(std::string parameter)
{
	double value = std::stod(parameter);
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
		char value = parameter[1];
		char_str.assign(1, value);
		int_str = strto
	}
	std::cout << "char: " << char_str << "\n";
	std::cout << "int: " << int_str << "\n";
	std::cout << "float: " << float_str << "\n";
	std::cout << "double: " << double_str << "\n";
}
