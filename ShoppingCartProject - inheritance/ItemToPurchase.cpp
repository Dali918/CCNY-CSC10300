#include "ItemToPurchase.h"

//Setter functions
void ItemToPurchase::SetName(string name)
{
    this->itemName = name;
}
void ItemToPurchase::SetPrice(int price)
{
    this->itemPrice = price;
}
void ItemToPurchase::SetQuantity(int quantity)
{
    this->itemQuantity = quantity;
}
void ItemToPurchase::SetDescription(string description)
{
    this->itemDescription = description;
}
//Getter functions
string ItemToPurchase::GetName() const
{
    return this->itemName;
}
int ItemToPurchase::GetPrice() const
{
    return this->itemPrice;
}
int ItemToPurchase::GetQuantity() const
{
    return this->itemQuantity;
}
int ItemToPurchase::GetCost() const
{
    return this->itemQuantity * this->itemPrice;
}
string ItemToPurchase::GetDescription() const
{
    return this->itemDescription;
}
void ItemToPurchase::PrintItemCost() const
{
    cout << this->GetName() << " " << this->GetQuantity() << " @ $" << this->GetPrice() << " = $" << this->GetCost() << endl;
}
void ItemToPurchase::PrintItemDescription() const
{
    cout << this->GetName() << ": " << this->GetDescription() << endl;
}
