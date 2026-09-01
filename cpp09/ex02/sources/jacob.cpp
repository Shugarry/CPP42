#include <iostream>

static int find_jacobsthal(int k)
{
    if (k == 0)
		return 0;
    if (k == 1)
		return 1;
    return find_jacobsthal(k - 1) + (2 * find_jacobsthal(k - 2));
}

int main()
{
	std::cout << "int sequence[] = { "; 
	for (int i = 0; i < 33; i++)
	{
		std::cout << find_jacobsthal(i) << ", ";
	}
	std::cout << " }"; 
}
