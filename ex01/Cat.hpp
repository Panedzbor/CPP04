#pragma once
#ifndef CAT_H
#define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat& original);
        Cat& operator=(const Cat& original);
        ~Cat();

        void makeSound() const;
    
    private:
        Brain* brain;
};

#endif