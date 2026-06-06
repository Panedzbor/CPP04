#include "WrongCat.hpp"

# include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Nobody make this pleasant WrongCat in the frontyard louder?\n";
    std::cout << "\n";
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal("WrongCat")
{
    (void)original;
}

WrongCat& WrongCat::operator=(const WrongCat& original)
{
    (void)original;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Awoooooooooooooow!\n";
    std::cout << "\n";
}