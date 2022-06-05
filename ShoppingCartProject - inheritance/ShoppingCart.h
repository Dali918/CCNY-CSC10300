#pragma once
#include "ItemToPurchase.h"

/*Build the ShoppingCart class with the following specifications. Note: Some can be function stubs (empty functions) initially, to be completed in later steps.
Default constructor
Parameterized constructor which takes the customer name and date as parameters (1 pt)   **done
Private data members    **done
string customerName - Initialized in default constructor to "none"
string currentDate - Initialized in default constructor to "January 1, 2016"
vector < ItemToPurchase > cartItems*/
class ShoppingCart
{
public:
    ShoppingCart(string name = "none", string date = "January 1, 2016") : customerName(name), currentDate(date)
    {
    }
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(ItemToPurchase item);
    void RemoveItem(string name);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void PrintTotal();
    void PrintDescriptions();

private:
    string customerName, currentDate;
    vector<ItemToPurchase> cartItems;
};
