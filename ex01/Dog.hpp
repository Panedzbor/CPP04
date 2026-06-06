#pragma once
#ifndef DOG_H
#define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& original);
        Dog& operator=(const Dog& original);
        ~Dog();

        void makeSound() const;
    
    private:
        Brain* brain;
};

#endif