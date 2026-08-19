#include <iostream>
#include "../headers/iter.hpp"

template <typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

template <typename T>
void increment(T& value)
{
	value++;
}

int main()
{
	int int_array[] = {1, 2, 3, 4, 5};

	std::cout << "original numbers:\n";
	iter(int_array, 5, print);
	iter(int_array, 5, increment);
	std::cout << "\nafter increment:\n";
	iter(int_array, 5, print);

	std::string str_array[] =
	{
		"hello",
		"world",
		"template"
	};
	std::cout << "\nstrings:\n" << std::endl;
	iter(str_array, 3, print);

	const int const_int_array[] = {10, 20, 30};
	std::cout << "\nconst numbers:" << std::endl;
	iter(const_int_array, 3, print);

	return 0;
}
