#pragma once
#ifndef W_CAT_H
#define W_CAT_H

# include "WrongAnimal.hpp"
# include <string>

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat& original);
        WrongCat& operator=(const WrongCat& original);
        ~WrongCat();

        void makeSound() const;
};

#endif