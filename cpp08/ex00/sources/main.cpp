#include "../headers/easyfind.hpp"

#include <vector>
#include <list>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    easyfind(v, 3);
    easyfind(v, 42);

    easyfind(l, 20);
    easyfind(l, 99);

    return 0;
}
