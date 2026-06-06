#pragma once
#ifndef W_ANIMAL_H
#define W_ANIMAL_H

# include <string>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& original);
        WrongAnimal& operator=(const WrongAnimal& original);
        virtual ~WrongAnimal();

        std::string getType() const;
        virtual void makeSound() const;
    protected:
        std::string type;
        WrongAnimal(std::string type);
};

#endif