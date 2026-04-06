#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include <iostream>
 
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Animal* animals[10];
 
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog;
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat;
 
	for (int i = 0; i < 10; i++)
		delete animals[i];
 
	std::cout << "Deep copy test: " << std::endl;

	Dog a;
	a.set_idea("woof woof", 0);
	Dog b(a);
	std::cout << "Original dog idea: " << a.get_idea(0) << " Copied dog idea: " << b.get_idea(0) << std::endl;

	std::cout << "Changing idea dog A to ruff ruff" << std::endl;
	a.set_idea("ruff ruff", 0);
	std::cout << "Original dog idea: " << a.get_idea(0) << " Copied dog idea: " << b.get_idea(0) << std::endl;
 
    return 0;
} 
