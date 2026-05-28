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
	int numbers[] = {1, 2, 3, 4, 5};

	std::cout << "Original numbers:" << std::endl;
	iter(numbers, 5, print);
	iter(numbers, 5, increment);
	std::cout << "\nAfter increment:" << std::endl;
	iter(numbers, 5, print);

	std::string words[] =
	{
		"hello",
		"world",
		"template"
	};

	std::cout << "\nStrings:" << std::endl;
	iter(words, 3, print);
	const int constNumbers[] = {10, 20, 30};
	std::cout << "\nConst numbers:" << std::endl;
	iter(constNumbers, 3, print);

	return 0;
}
