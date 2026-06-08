#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        array[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& original)
{
    for (int i = 0; i < 4; i++)
    {
        if (original.array[i])
            this->array[i] = original.array[i]->clone();
        else
            this->array[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& original)
{
    if (this == &original)
        return (*this);
    for (int i = 0; i < 4; i++)
    {
        delete this->array[i];
        if (original.array[i])
            this->array[i] = original.array[i]->clone();
        else
            this->array[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->array[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!array[i])
        {
            array[i] = m->clone();
            break;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 3; i >= 0; i--)
    {
        if (array[i] && type == array[i]->getType())
            return ((array[i])->clone());
    }
    return 0;
}

const AMateria* MateriaSource::getMateriaSource(const int idx) const
{
    return array[idx];
}