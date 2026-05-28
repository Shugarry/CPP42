#include <iostream>
#include "../headers/Array.hpp"

int main()
{
	Array<int> a;

	Array<int> b(5);
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i * 10;

	Array<int> c(b);

	b[0] = 999;

	std::cout << "b[0]: " << b[0] << "\n";
	std::cout << "c[0]: " << c[0] << "\n";

	Array<int> d;
	d = c;

	c[1] = 777;

	std::cout << "c[1]: " << c[1] << "\n";
	std::cout << "d[1]: " << d[1] << "\n";

	std::cout << "size b: " << b.size() << "\n";

	try
	{
		std::cout << b[100] << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught" << "\n";
	}

	return 0;
}
