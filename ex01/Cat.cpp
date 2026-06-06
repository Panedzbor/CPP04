#include "Cat.hpp"

# include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Somebody shut up this annoying cat in the backyard!\n";
    std::cout << "\n";
}

Cat::Cat(const Cat& original) : Animal("Cat")
{
    (void)original;
}

Cat& Cat::operator=(const Cat& original)
{
    (void)original;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "MEAAAAAAAAAAAAAAAAAAUUUUU!\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow\n";
    std::cout << "\n";
}