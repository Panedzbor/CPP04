#pragma once
#ifndef CHAR_H
#define CHAR_H

# include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character(std::string name);
        Character(const Character& original);
        Character& operator=(const Character& original);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        const AMateria *getInventory(const int idx) const;
    
    private:
        std::string name;
        AMateria* inventory[4];
        Character();
};

#endif