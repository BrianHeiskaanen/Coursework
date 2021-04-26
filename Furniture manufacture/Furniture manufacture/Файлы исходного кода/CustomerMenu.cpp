#include "CustomerMenu.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void CustomerMenu::customerMenu()
{
    CustomerMenu::delimiter();
    
    int tmp;
    
    cout << "Customer menu" << endl;
    cout << "1) Make an order" << endl;
    cout << "2) View orders" << endl;
    cout << "3) Cancel the order" << endl;
    cout << "4) Find an order" << endl;
    cout << "5) Exit" << endl << endl;
    cout << "Your choice: "; cin >> tmp;
    
    if(tmp == 1) {
        CustomerMenu::makeAnOrder();
    }else if(tmp == 2) {
        CustomerMenu::viewOrders();
    }else if(tmp == 3) {
        CustomerMenu::cancelTheOrder();
    }else if(tmp == 4) {
        CustomerMenu::findAnOrder();
    }else if(tmp == 5) {
        exit(0);
    }else {
        cout << endl;
        cout << "There is no such answer. Try again" << endl;
    }
    
    CustomerMenu::customerMenu();
}

void CustomerMenu::makeAnOrder()
{
    CustomerMenu::delimiter();
    
    string customerName, orderDate, furniture;
    
    cout << "Enter customer name: "; cin >> customerName;
    cout << "Enter order date: "; cin >> orderDate;
    cout << "Enter the furniture you need: "; cin >> furniture;
    
    ofstream out;
    out.open("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/orders.txt", ios::app);
    if (out.is_open())
    {
        out << customerName << endl;
        out << orderDate << endl;
        out << furniture << endl;
        out << endl;
    }
    out.close();
    
    cout << endl;
    cout << "Application added!" << endl;
}

void CustomerMenu::viewOrders()
{
    CustomerMenu::delimiter();

    string line;
     
    ifstream in("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/orders.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
}

void CustomerMenu::cancelTheOrder()
{
    CustomerMenu::delimiter();

    string line;
    int numberOfLines = 0, numberOfOrders = 0, orderNumber = 0;
    vector<string> file;
     
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
    
    cout << "Select the order number to delete. Total orders: ";
    cout << numberOfOrders << endl;
    cout << "Order number: "; cin >> orderNumber;
    cout << endl;
    
    if(orderNumber < 1 || orderNumber > numberOfOrders){
        cout << "There is no order with this number!" << endl;
        CustomerMenu::cancelTheOrder();
    }else{
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
    
    cout << "Application deleted!" << endl;
}

void CustomerMenu::findAnOrder()
{
    CustomerMenu::delimiter();

    string str, line;
    int number = 1;
    int tmp = 0;
    vector<string> newStr;
    
    cout << "Enter customer name to search: "; cin >> str;
    
    ifstream in;
    in.open("/Users/maksim/Desktop/Projects/Coursework/Furniture manufacture/orders.txt");

    while (!in.eof()) {
        getline(in, line);
        
        newStr.push_back(line);
        
        if(line == str) {
            str = "good";
            tmp = number;
        }
        else {
            number++;
        }
    }
    
    in.close();
    
    if(str == "good"){
        cout << endl;
        
        for (int i = tmp - 1; i < tmp + 2; i++)
        {
            cout << newStr[i] << endl;
        }
    }
    else{
        cout << endl;
        cout << "Nothing found!";
        cout << endl;
    }
}

void CustomerMenu::delimiter()
{
    cout << endl;
    cout << "--------------------------------------------";
    cout << endl << endl;
}
