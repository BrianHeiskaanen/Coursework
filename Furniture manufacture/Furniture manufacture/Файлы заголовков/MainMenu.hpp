#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>
#include "CustomerMenu.hpp"
#include "SupplierMenu.hpp"

class MainMenu : public CustomerMenu, public SupplierMenu{
public:
    static void mainMenu();
private:
    static void delimiter();
};

#endif /* MainMenu_hpp */
