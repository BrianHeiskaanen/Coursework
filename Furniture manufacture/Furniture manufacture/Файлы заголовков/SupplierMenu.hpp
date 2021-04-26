#ifndef SupplierMenu_hpp
#define SupplierMenu_hpp

#include <stdio.h>
#include "CustomerMenu.hpp"

class SupplierMenu : public CustomerMenu{
protected:
    static void supplierMenu();
private:
    static void delimiter();
    static void acceptOrders();
    static void viewAcceptOrders();
};

#endif /* SupplierMenu_hpp */
