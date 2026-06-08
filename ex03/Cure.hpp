#pragma once
#ifndef CURE_H
#define CURE_H

# include <string>
# include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        Cure(const Cure& original);
        Cure& operator=(const Cure& original);
        ~Cure();
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif