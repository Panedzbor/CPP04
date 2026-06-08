#pragma once
#ifndef MATSOURCE_H
#define MATSOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& original);
        MateriaSource& operator=(const MateriaSource& original);        
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
        const AMateria* getMateriaSource(const int idx) const;
    
    private:
        AMateria* array[4];
};

#endif