#include "SupplierMenu.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void SupplierMenu::supplierMenu()
{
    SupplierMenu::delimiter();
    
    int tmp;
    
    cout << "Supplier menu" << endl;
    cout << "1) View orders" << endl;
    cout << "2) View accept orders" << endl;
    cout << "3) Accept orders" << endl;
    cout << "4) Cancel the order" << endl;
    cout << "5) Find an order" << endl;
    cout << "6) Exit" << endl << endl;
    cout << "Your choice: "; cin >> tmp;
    
    if(tmp == 1) {
        CustomerMenu::viewOrders();
    }else if(tmp == 2) {
        SupplierMenu::viewAcceptOrders();
    }else if(tmp == 3) {
        SupplierMenu::acceptOrders();
    }else if(tmp == 4) {
        CustomerMenu::cancelTheOrder();
    }else if(tmp == 5) {
        CustomerMenu::findAnOrder();
    }else if(tmp == 6) {
        exit(0);
    }else {
        cout << endl;
        cout << "There is no such answer. Try again" << endl;
    }
    
    SupplierMenu::supplierMenu();
}

void SupplierMenu::acceptOrders()
{
    SupplierMenu::delimiter();

    string line;
    int numberOfLines = 0, numberOfOrders = 0, orderNumber = 0;
    vector<string> file, newFile;
     
    ifstream in("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/orders.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            numberOfLines++;
            file.push_back(line);
        }
    }
    numberOfOrders = numberOfLines / 4;
    
    in.close();
    
    cout << "Select the order number to accept. Total orders: ";
    cout << numberOfOrders << endl;
    cout << "Order number: "; cin >> orderNumber;
    cout << endl;
    
    if(orderNumber < 1 || orderNumber > numberOfOrders){
        cout << "There is no order with this number!" << endl;
        CustomerMenu::cancelTheOrder();
    }else{
        for (int i = orderNumber * 4 - 4; i < orderNumber * 4; i++) {
            newFile.push_back(file[i]);
        }
        
        ofstream out1;
        out1.open("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/acceptOrders.txt", ios::app);
        if (out1.is_open())
        {
            for(int i = 0; i < newFile.size(); i++){
                out1 << newFile[i] << endl;
            }
        }
        out1.close();
        
        file.erase(file.begin() + (orderNumber * 4 - 4), file.begin() + orderNumber * 4);
        
        ofstream out;
        out.open("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/orders.txt");
        if (out.is_open())
        {
            for(int i = 0; i < file.size(); i++){
                out << file[i] << endl;
            }
        }
        out.close();
    }
    
    cout << "Application accepted!" << endl;
}

void SupplierMenu::delimiter()
{
    cout << endl;
    cout << "--------------------------------------------";
    cout << endl << endl;
}

void SupplierMenu::viewAcceptOrders()
{
    SupplierMenu::delimiter();

    string line;
     
    ifstream in("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/acceptOrders.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
}
