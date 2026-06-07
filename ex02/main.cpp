#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    int n = 10;
    Animal* zoo[n];

    //test 1
    std::cout << "Test 1\n";
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            zoo[i] = new Cat();
        else
            zoo[i] = new Dog();
    }
    for (int i = 0; i < n; i++)
        delete zoo[i];
    std::cout << "\n";

    //test 2
    std::cout << "Test 2\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;  
    std::cout << "\n";  
    
    //test 3
    std::cout << "Test 3\n";
    // Animal animal;
    Dog dog;
    Cat cat;
    Brain brain;
    // Animal *animalPtr = new Animal();
    Dog* dogPtr = new Dog();
    Cat* catPtr = new Cat();
    Brain* brainPtr = new Brain();
    // Animal* anCopy = new Animal(*animalPtr);
    Dog* doCopy = new Dog(*dogPtr);
    Cat* caCopy = new Cat(*catPtr);
    Brain* brCopy = new Brain(*brainPtr);
    // animal = animal;
    dog = dog;
    cat = cat;
    brain = brain;
    // *animalPtr = *animalPtr;
    *dogPtr = *dogPtr;
    *catPtr = *catPtr;
    *brainPtr = *brainPtr;
    // Animal aCopy(animal);
    Dog dCopy(dog);
    Cat cCopy(cat);
    Brain bCopy(brain);
    // delete animalPtr;
    delete dogPtr;
    delete catPtr;
    delete brainPtr;
    // delete anCopy;
    delete doCopy;
    delete caCopy;
    delete brCopy;
    return 0;
}