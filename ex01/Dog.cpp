#include "Dog.hpp"

# include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Who let the dog out? Augh! Augh! Augh! Augh! Augh!\n";

    brain = new Brain();

    std::cout << "\n";
}

Dog::Dog(const Dog& original) : Animal("Dog")
{
    (void)original;
}

Dog& Dog::operator=(const Dog& original)
{
    (void)original;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Sad augh :(\n";

    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Augh!\n";
    std::cout << "\n";
}