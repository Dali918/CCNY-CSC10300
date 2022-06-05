//Dalitso Banda CSC10300 CC1

#include "ShoppingCart.h"
void PrintMenu()
{
    cout << "MENU\n"
         << "a - Add item to cart\n"
         << "d - Remove item from cart\n"
         << "c - Change item quantity\n"
         << "i - Output items' descriptions\n"
         << "o - Output shopping cart\n"
         << "q - Quit\n";
    cout << endl;
}
/*Implement the ExecuteMenu() function in main.cpp that takes 2 parameters: a character representing the user's choice and the reference of a shopping cart. ExecuteMenu() performs the menu options described below, according to the user's choice. (1 pt)*/
void ExecuteMenu(char choice, ShoppingCart &rcart)
{
    string name, description;
    int price, quantity;
    if (choice == 'a')
    {
        cin.ignore();
        cout << "ADD ITEM TO CART\n";
        cout << "Enter the item name:\n";
        getline(cin, name);
        cout << "Enter the item description:\n";
        getline(cin, description);
        cout << "Enter the item price:\n";
        cin >> price;
        cout << "Enter the item quantity:\n";
        cin >> quantity;

        ItemToPurchase item(name, description, price, quantity);
        rcart.AddItem(item);
    }
    else if (choice == 'd')
    {
        cin.ignore();
        cout << "REMOVE ITEM FROM CART\n"
             << "Enter name of item to remove:\n";
        getline(cin, name);
        rcart.RemoveItem(name);
    }
    else if (choice == 'c')
    {
        cin.ignore();
        cout << "CHANGE ITEM QUANTITY\n"
             << "Enter the item name:\n";
        getline(cin, name);
        cout << "Enter the new quantity:\n";
        cin >> quantity;
        ItemToPurchase item(name);
        item.SetQuantity(quantity);
        rcart.ModifyItem(item);
    }
    else if (choice == 'i')
    {
        cin.ignore();
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        rcart.PrintDescriptions();
        
    }
    else if (choice == 'o')
    {
        cin.ignore();
        cout << "OUTPUT SHOPPING CART" << endl;
        rcart.PrintTotal();
        
    }

    cout<<endl;
}
int main()
{
    string name, date;
    cout << "Enter customer's name:\n";
    getline(cin, name);
    cout << "Enter today's date:\n";
    getline(cin, date);
    cout << endl;
    cout << "Customer name: " << name << "\nToday's date: " << date << endl;
    cout << endl;
    ShoppingCart cart(name, date);

    char choice = ' ';
    PrintMenu();

    while (choice != 'q')
    {
        cout << "Choose an option:\n";
        cin >> choice;
        if (choice == 'a' || choice == 'd' || choice == 'c' || choice == 'i' || choice == 'o')
        {
            ExecuteMenu(choice, cart);
            PrintMenu();
        }
        
    }
    return 0;
}
