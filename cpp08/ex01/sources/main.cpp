#include "../headers/Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.add_number(6);
	sp.add_number(3);
	sp.add_number(17);
	sp.add_number(9);
	sp.add_number(11);
	std::cout << sp.shortest_span() << std::endl;
	std::cout << sp.longest_span() << std::endl;
	return 0;
}
