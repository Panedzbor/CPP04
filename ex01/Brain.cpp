#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain default constructor called\n";
    std::cout << "\n";
}

Brain::Brain(const Brain& original)
{
    std::cout << "Brain copy constructor called\n";
    
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = original.ideas[i];
    
    std::cout  << "\n";
}

Brain& Brain::operator=(const Brain& original)
{
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = original.ideas[i];   
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";

    delete[] ideas;
}