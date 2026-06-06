#include "Animal.hpp"

# include <iostream>

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called\n";
    std::cout << "\n";
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor called\n";
    std::cout << "\n";
}

Animal::Animal(const Animal& original)
{
    (void)original;
}

Animal& Animal::operator=(const Animal& original)
{
    (void)original;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const
{
    std::cout << "...some animal sound...\n";
    std::cout << "\n";
}

std::string Animal::getType() const
{
    return (type);
}