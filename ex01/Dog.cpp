#include "Dog.hpp"

# include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Who let the dog out? Augh! Augh! Augh! Augh! Augh!\n";

    brain = new Brain();

    std::cout << "\n";
}

Dog::Dog(const Dog& original) : Animal(original)
{
    std::cout << "Dog copy constructor called\n";

    this->brain = new Brain(*original.brain);

    std::cout << "\n";
}

Dog& Dog::operator=(const Dog& original)
{
    if (this == &original)
        return (*this);
    this->type = original.type;
    delete this->brain;
    this->brain = new Brain(*original.brain);
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