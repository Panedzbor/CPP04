#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& original) : name(original.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (original.inventory[i])
            this->inventory[i] = original.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& original)
{
    if (this == &original)
        return (*this);
    name = original.name;
    for (int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
        if (original.inventory[i])
            this->inventory[i] = original.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return (*this);
}
        
Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        inventory[idx] = NULL;
}
        
void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && inventory[idx])
        inventory[idx]->use(target);
}

const AMateria* Character::getInventory(const int idx) const
{
    return (inventory[idx]);
}