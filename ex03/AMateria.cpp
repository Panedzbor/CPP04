#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& original) : type(original.type) {}
        
AMateria& AMateria::operator=(const AMateria& original)
{
    (void)original;
    return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}