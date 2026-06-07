#include "Cat.hpp"

# include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Somebody shut up this annoying cat in the backyard!\n";

    brain = new Brain();

    std::cout << "\n";
}

Cat::Cat(const Cat& original) : Animal(original)
{
    std::cout << "Cat copy constructor called\n";

    this->brain = new Brain(*original.brain);

    std::cout << "\n";
}

Cat& Cat::operator=(const Cat& original)
{
    if (this == &original)
        return (*this);
    this->type = original.type;
    delete this->brain;
    this->brain = new Brain(*original.brain);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "MEAAAAAAAAAAAAAAAAAAUUUUU!\n";

    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow\n";
    std::cout << "\n";
}