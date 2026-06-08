#pragma once
#ifndef AMATERIA_H
#define AMATERIA_H

# include <string>
# include "Character.hpp"

class AMateria
{
    private:
        AMateria();
        
    protected:
        std::string const type;

    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& original);
        AMateria& operator=(const AMateria& original);
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif