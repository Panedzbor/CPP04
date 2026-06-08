#include "testkit_lib.hpp"

std::string giveName(std::string who)
{
    std::string name;
    
    std::cout << "Enter " << who << "'s name: ";
    while (!std::getline(std::cin, name) || name.empty())
    {
        std::cin.ignore(1000, '\n');
        std::cout << "Give a valid name: ";
    }
    std::cout << '\n';
    return name;
}

char getInput(const std::string& allowed)
{
    char input = 0;

    while (true)
    {
        std::cout << "Enter your choice: ";
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        if (allowed.find(input) != std::string::npos)
            break;
    }
    std::cout << '\n';
    return input;
}