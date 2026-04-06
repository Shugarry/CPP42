#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
 
int main()
{
	//Animal test;
	//Animal* test2 = new Animal();

	Animal* dog = new Dog(); 
	dog->makeSound();
    
    return 0;
} 
