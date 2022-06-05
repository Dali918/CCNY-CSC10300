#include "ShoppingCart.h"
string ShoppingCart::GetCustomerName() const
{
    return this->customerName;
}
string ShoppingCart::GetDate() const
{
    return this->currentDate;
}
/*
GetNumItemsInCart() (2 pts)
Returns quantity of all items in cart. Has no parameters.*/
int ShoppingCart::GetNumItemsInCart() const
{
    int count = 0;
    for (auto &item : this->cartItems)
    {
        count += item.GetQuantity();
    }
    return count;
}
/*
GetCostOfCart() (2 pts)
Determines and returns the total cost of items in cart. Has no parameters.*/
int ShoppingCart::GetCostOfCart() const
{
    int cost = 0;
    for (auto &item : this->cartItems)
    {
        cost += item.GetCost();
    }
    return cost;
}
/*AddItem()
Adds an item to cartItems vector. Has parameter ItemToPurchase. Does not return anything.*/
void ShoppingCart::AddItem(ItemToPurchase item)
{
    this->cartItems.push_back(item);
}
/*RemoveItem()
Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
If item name cannot be found, output this message: Item not found in cart. Nothing removed.
*/
void ShoppingCart::RemoveItem(string name)
{
    for (unsigned i = 0; i < this->cartItems.size(); i++)
    {
        if (this->cartItems.at(i).GetName() == name)
        {
            this->cartItems.erase(this->cartItems.begin() + i);
            return;
        }
    }

    cout << "Item not found in cart. Nothing removed." << endl;
}
/*ModifyItem()
Modifies an item's description, price, and/or quantity. Has parameter ItemToPurchase. Does not return anything.
If item can be found (by name) in cart, check if parameter has default values for description, price, and quantity. If not, modify item in cart.
If item cannot be found (by name) in cart, output this message: Item not found in cart. Nothing modified.*/
void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    for (unsigned i = 0; i < this->cartItems.size(); i++)
    {
        if (this->cartItems.at(i).GetName() == item.GetName())
        {
            ItemToPurchase &ritem = this->cartItems.at(i);
            if (ritem.GetDescription() != "none" && ritem.GetCost() != 0 && ritem.GetPrice() != 0)
            {
                ritem.SetQuantity(item.GetQuantity());
                return;
            }
        }
    }

    cout << "Item not found in cart. Nothing modified." << endl;
}
/*
PrintTotal()
Outputs total of objects in cart.*/
void ShoppingCart::PrintTotal()
{
    /*
    John Doe's Shopping Cart - February 1, 2016
Number of Items: 8

Nike Romaleos 2 @ $189 = $378
Chocolate Chips 5 @ $3 = $15
Powerbeats 2 Headphones 1 @ $128 = $128

Total: $521*/
    cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << "\n"
         << "Number of Items: " << this->GetNumItemsInCart() << "\n";
    cout << endl;
    if (this->GetNumItemsInCart() == 0)
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else
    {

        for (auto &item : this->cartItems)
        {
            item.PrintItemCost();
        }
    }
    cout << endl;
    cout << "Total: $" << this->GetCostOfCart()<<endl;
}
/*
If cart is empty, output this message: SHOPPING CART IS EMPTY
PrintDescriptions()*/
void ShoppingCart::PrintDescriptions()
{
    /*John Doe's Shopping Cart - February 1, 2016

Item Descriptions
Nike Romaleos: Volt color, Weightlifting shoes
Chocolate Chips: Semi-sweet
Powerbeats 2 Headphones: Bluetooth headphones*/
    cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << "\n";
    cout << endl;
    if (this->GetNumItemsInCart() == 0)
    
        cout << "SHOPPING CART IS EMPTY" << endl
        return
    
    els
    
        cout << "Item Descriptions\n"
        for (auto &item : this->cartItems)
        {
            item.PrintItemDescription();
        }
    }
  

}
