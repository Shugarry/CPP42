#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
bool easyfind(const T& container, int x)
{
	typename T::const_iterator iterator = std::find(container.begin(), container.end(), x);
	if (iterator == container.end())
	{
		std::cout << "element " << x << " NOT found in container\n";
		return false;
	}
	std::cout << "element " << x << " found in container\n";
	return true;
}


#endif
