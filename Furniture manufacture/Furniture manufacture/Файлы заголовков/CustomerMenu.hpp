#ifndef CustomerMenu_hpp
#define CustomerMenu_hpp

#include <stdio.h>

class CustomerMenu {
protected:
    static void customerMenu();
private:
    static void delimiter();
    static void makeAnOrder();
protected:
    static void viewOrders();
    static void cancelTheOrder();
    static void findAnOrder();
};

#endif /* CustomerMenu_hpp */
