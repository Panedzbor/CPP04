#include "WrongAnimal.hpp"

# include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called\n";
    std::cout << "\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal constructor called\n";
    std::cout << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
    (void)original;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
    (void)original;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "...some WrongAnimal sound...\n";
    std::cout << "\n";
}

std::string WrongAnimal::getType() const
{
    return (type);
}