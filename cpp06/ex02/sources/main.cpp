#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"
#include <iostream>

Base* generate()
{
	Base *tmp;
	int x = std::rand() % 3;

	if (x == 0)
		tmp = new A();
	else if (x == 1)
		tmp = new B();
	else
		tmp = new C();
	return tmp;
}

void	identify(Base *p)
{
	if (dynamic_cast<A* >(p))
		std::cout << "A\n";
	else if (dynamic_cast<B* >(p))
		std::cout << "B\n";
	else if (dynamic_cast<C* >(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
    try
	{
        (void)dynamic_cast<A& >(p);
        std::cout << "A\n";
        return;
    }
    catch (std::exception&) {}

    try
	{
        (void)dynamic_cast<B& >(p);
        std::cout << "B\n";
        return;
    }
    catch (std::exception&) {}

    try
	{
        (void)dynamic_cast<C& >(p);
        std::cout << "C\n";
        return;
    }
    catch (std::exception&) {}
}

int main()
{
	std::srand(std::time(0));

    A a;
    B b;
    C c;

    Base* ptr_a = &a;
    Base* ptr_b = &b;
    Base* ptr_c = &c;

    std::cout << "Pointer tests:\n";
    identify(ptr_a);
    identify(ptr_b);
    identify(ptr_c);

    std::cout << "Reference tests:\n";
    identify(a);
    identify(b);
    identify(c);

    std::cout << "Edge case:\n";
    Base base;
	Base* ptr_base = &base;

	identify(ptr_base);
	identify(base);
}
