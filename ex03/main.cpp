#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include "testkit_lib/testkit_lib.hpp"

// int main()
// {
//     Character C("John");
//     std::cout << "Name: " << C.getName() << "\n";

//     Ice* I = new Ice();
//     I->use(C);

//     Cure* Q = new Cure();
//     Q->use(C);

//     C.equip(I);
//     C.equip(Q);

//     MateriaSource M;
//     M.learnMateria(I);
//     M.learnMateria(Q);
//     C.equip(M.createMateria(I->getType()));
//     return 0;
// }

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
    
//     ICharacter* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
    
//     ICharacter* bob = new Character("bob");
    
//     me->use(0, *bob);
//     me->use(1, *bob);
    
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

static void displayMenu(void);
static void executeAction(char input, IMateriaSource* spellbook, ICharacter *C);
static void openInventory(ICharacter *C);
static void subMenuInventory(void);
static void useMateria(ICharacter *C);
static void dropItem(ICharacter* C);
static void openSpellbook(IMateriaSource* spellbook, ICharacter *C);
static void subMenuSpellbook(void);
void createSpell(IMateriaSource* spellbook, ICharacter* C);
static void equipSpell(AMateria* spell, ICharacter* C);
static void subMenuEquip(void);
static void searchRecipe(IMateriaSource* spellbook, ICharacter* C);
static int getSecsSinceMidnight(void);
static void subMenuRecipe();
static void showName(ICharacter *C);

int main()
{
    IMateriaSource* spellbook = new MateriaSource();
    ICharacter *C = new Character(giveName("character"));
    char input = 0;

    std::cout << "Hi " << C->getName() << ", nice to see you!\n";
    std::cout << "\n";
    while (input != 'e')
    {
        displayMenu();
        input = getInput("1234e");
        executeAction(input, spellbook, C);
    }
    delete spellbook;
    delete C;
    return 0;
}

static void displayMenu(void)
{
    std::cout << "1: Open inventory\n";
    std::cout << "2: Open the spellbook\n";
    std::cout << "3. Search for a recipe\n";
    std::cout << "4: Remind me my name\n";
    std::cout << "e: Exit\n";
    std::cout << '\n';
}

static void executeAction(char input, IMateriaSource* spellbook, ICharacter *C)
{
    switch (input)
    {
        case '1':
            openInventory(C);
            break;
        case '2':
            openSpellbook(spellbook, C);
            break;
        case '3':
            searchRecipe(spellbook, C);
            break;
        case '4':
            showName(C);
            break;
    }
}

static void openInventory(ICharacter *C)
{
    std::cout << "INVENTORY:\n";
    std::cout << std::setw(7) << "slot1";
    std::cout << std::setw(7) << "slot2";
    std::cout << std::setw(7) << "slot3";
    std::cout << std::setw(7) << "slot4";
    std::cout << "\n";
    Character* c = dynamic_cast<Character*>(C);
    for (int i = 0; i < 4; i++)
    {
        if (c->getInventory(i))
            std::cout << std::setw(7) << c->getInventory(i)->getType();
        else
            std::cout << std::setw(7) << "empty";
    }
    std::cout << "\n\n";
    subMenuInventory();
    char input = getInput("123");
    if (input == '1')
        useMateria(C);
    if (input == '2')
        dropItem(C);
    std::cout << "\n";
}

static void subMenuInventory(void)
{
    std::cout << "1: Use inventory item\n";
    std::cout << "2: Drop inventory item\n";
    std::cout << "3: Back\n";
    std::cout << '\n';
}

static void useMateria(ICharacter* C)
{
    std::cout << "Choose the item slot\n";
    char input = getInput("1234");
    int i = input - '0' - 1;
    Character* c = dynamic_cast<Character*>(C);
    if (c->getInventory(i))
        C->use(i, *C);
    else
        std::cout << "Slot empty\n";
    std::cout << "\n";
}

static void dropItem(ICharacter* C)
{
    std::cout << "Choose the item slot\n";
    char input = getInput("1234");
    int i = input - '0' - 1;
    Character* c = dynamic_cast<Character*>(C);
    if (c->getInventory(i))
    {
        const AMateria* tmp = c->getInventory(i);
        C->unequip(i);
        delete tmp;
        std::cout << "\n";
        openInventory(C);
    }
    else
    {
        std::cout << "Slot empty\n";
        std::cout << "\n";
    }
}

static void openSpellbook(IMateriaSource* spellbook, ICharacter* C)
{
    std::cout << "SPELLBOOK:\n";
    std::cout << std::setw(7) << "rec1";
    std::cout << std::setw(7) << "rec2";
    std::cout << std::setw(7) << "rec3";
    std::cout << std::setw(7) << "rec4";
    std::cout << "\n";
    MateriaSource* ms = dynamic_cast<MateriaSource*>(spellbook);
    for (int i = 0; i < 4; i++)
    {
        if (ms->getMateriaSource(i))
            std::cout << std::setw(7) << ms->getMateriaSource(i)->getType();
        else
            std::cout << std::setw(7) << "empty";
    }
    std::cout << "\n\n";
    subMenuSpellbook();
    char input = getInput("12");
    if (input == '1')
        createSpell(spellbook, C);
    std::cout << "\n";
}

static void subMenuSpellbook(void)
{
    std::cout << "1: Create a spell\n";
    std::cout << "2: Back\n";
    std::cout << '\n';
}

void createSpell(IMateriaSource* spellbook, ICharacter* C)
{
    std::cout << "Select a spell\n";
    char input = getInput("1234");
    int i = input - '0' - 1;
    MateriaSource* ms = dynamic_cast<MateriaSource*>(spellbook);
    if (ms->getMateriaSource(i))
    {
        AMateria* temp = spellbook->createMateria(ms->getMateriaSource(i)->getType());
        std::cout << "Spell " << ms->getMateriaSource(i)->getType() << " created\n";
        equipSpell(temp, C);
    }
    else
        std::cout << "Slot empty\n";
    std::cout << "\n";
}

static void equipSpell(AMateria* spell, ICharacter* C)
{
    std::cout << "Do you want to equip " << spell->getType() << " to inventory?\n";
    subMenuEquip();
    char input = getInput("12");
    if (input == '1')
    {
        C->equip(spell);
        std::cout << '\n';
        openInventory(C);
    }
    else
    {
        delete spell;
        std::cout << '\n';
    }
}

static void subMenuEquip(void)
{
    std::cout << "1: Yes\n";
    std::cout << "2: No\n";
    std::cout << '\n';
}

static void searchRecipe(IMateriaSource* spellbook, ICharacter* C)
{
    AMateria* spell;

    int rand_num = getSecsSinceMidnight() % 2;
    if (rand_num)
    {
        std::cout << "You found a recipe for ice! ";
        spell = new Ice();
    }
    else
    {
        std::cout << "You found a recipe for cure! ";
        spell = new Cure();
    }
    std::cout << "Would you like to save it in the spellbook?\n";
    subMenuRecipe();
    char input = getInput("12");
    if (input == '1')
    {
        spellbook->learnMateria(spell);
        openSpellbook(spellbook, C);
    }
    else
        delete spell;
    std::cout << "\n";
}

static int getSecsSinceMidnight()
{
    std::time_t now = std::time(NULL);
    std::tm* local = std::localtime(&now);

    int seconds_since_midnight =
        local->tm_hour * 3600 +
        local->tm_min * 60 +
        local->tm_sec;
    return seconds_since_midnight;
}

static void subMenuRecipe()
{
    std::cout << "1: Yes\n";
    std::cout << "2: No\n";
    std::cout << '\n';
}

static void showName(ICharacter *C)
{
    std::cout << "Your character's name is " << C->getName() << "\n";
    std::cout << "\n";
}