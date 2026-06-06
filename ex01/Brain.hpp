#pragma once
#ifndef BRAIN_H
#define BRAIN_H

# include <string>

class Brain {
    public:
        Brain();
        Brain(const Brain& original);
        Brain& operator=(const Brain& original);
        ~Brain();
        
        std::string ideas[100];
};

#endif