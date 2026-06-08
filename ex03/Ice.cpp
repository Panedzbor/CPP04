#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& original) : AMateria(original) {}

Ice& Ice::operator=(const Ice& original)
{
    (void)original;
    return (*this);
}

Ice::~Ice() {}
        
AMateria* Ice::clone() const
{
    AMateria* newIce = new Ice(*this);
    return (newIce);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}