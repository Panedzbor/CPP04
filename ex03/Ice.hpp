#pragma once
#ifndef ICE_H
#define ICE_H

# include <string>
# include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice& original);
        Ice& operator=(const Ice& original);
        ~Ice();
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif