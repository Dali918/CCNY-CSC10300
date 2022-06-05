#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ItemToPurchase
{
public:
    ItemToPurchase(string name = "none", string description = "none", int price = 0, int quantity = 0) : itemName(name),
                                                                                                         itemDescription(description),
                                                                                                         itemPrice(price),
                                                                                                         itemQuantity(quantity)
    {
    }

    //Setter functions
    void SetName(string name);
    void SetPrice(int price);
    void SetQuantity(int quantity);
    void SetDescription(string description);

    //Getter functions
    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    int GetCost() const;
    string GetDescription() const;
    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    string itemName, itemDescription;
    int itemPrice, itemQuantity;
};