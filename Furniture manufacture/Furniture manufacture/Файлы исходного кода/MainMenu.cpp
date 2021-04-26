#include "MainMenu.hpp"
#include <iostream>

using namespace std;

void MainMenu::mainMenu()
{
    int tmp;
    
    cout << "Main menu" << endl;
    cout << "1) Customer menu" << endl;
    cout << "2) Supplier menu" << endl;
    cout << "3) Exit" << endl << endl;
    cout << "Your choice: "; cin >> tmp;
    
    cout << endl;
    
    if(tmp == 1) {
        CustomerMenu::customerMenu();
    }else if(tmp == 2) {
        SupplierMenu::supplierMenu();
    }else if(tmp == 3) {
        exit(0);
    }else {
        cout << "There is no such answer. Try again" << endl;
        MainMenu::delimiter();
        MainMenu::mainMenu();
    }
}

void MainMenu::delimiter()
{
    cout << endl;
    cout << "--------------------------------------------";
    cout << endl << endl;
}
