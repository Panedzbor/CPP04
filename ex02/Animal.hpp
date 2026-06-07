#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

# include <string>

class Animal {
    public:
        Animal();
        Animal(const Animal& original);
        Animal& operator=(const Animal& original);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const = 0;
    protected:
        std::string type;
        Animal(std::string type);
};

#endif