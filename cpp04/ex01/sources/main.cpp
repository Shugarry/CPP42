#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include <iostream>
 
int main()
{ 
	Animal* animals[10];
 
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog;
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat;
 
	for (int i = 0; i < 10; i++)
		delete animals[i];
 
	std::cout << "Deep copy test: " << std::endl;
 
	Dog a;
	Dog b(a);

	Cat c;
	Cat d(c);
 
    return 0;
} 
