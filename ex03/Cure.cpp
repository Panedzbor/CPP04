#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& original) : AMateria(original) {}

Cure& Cure::operator=(const Cure& original)
{
    (void)original;
    return (*this);
}

Cure::~Cure() {}
        
AMateria* Cure::clone() const
{
    AMateria* newCure = new Cure(*this);
    return (newCure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}