#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " says: ";
    j->makeSound();
    std::cout << i->getType() << " says: ";
    i->makeSound();
    std::cout << meta->getType() << " says: ";
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << wrong_cat->getType() << " says: ";
    wrong_cat->makeSound();
    std::cout << wrong_meta->getType() << " says: ";
    wrong_meta->makeSound();
    delete wrong_meta;
    delete wrong_cat;

    Cat a;
    Cat b(a);
    Cat c;
    c = a;

    std::cout << "Original Cat type: " << a.getType() << std::endl;
    std::cout << "Copied Cat type: " << b.getType() << std::endl;
    std::cout << "Assigned Cat type: " << c.getType() << std::endl;

    return 0;
}
