#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cassert>


using namespace std;
struct Product
{
    string description; // Product description
    int partNum;        // Part number
    double cost;        // Product cost

    //default constructor
    Product() : description(""), partNum(0), cost(0) {}
    //parameter constructor
    Product(string description, int partNum, double cost)
    {
        this->description = description;
        this->partNum = partNum;
        this->cost = cost;
    }

    //struct print function

    void print()
    {
        cout << left << setw(13) << "Description:" << this->description << endl;
        cout << left << setw(13) << "Number:" << this->partNum << endl;
        cout << left << setw(13) << "Part Cost:";
        cout << "$" << this->cost << endl;
    }
};

//Print Product array function
void print(Product *itemArray, int len)
{
    //loop through array
    for (int i = 0; i < len; ++i)
    {
        //print each item
        cout << "Item " << i + 1 << endl;
        itemArray[i].print();
        cout << endl;
    }
}

//max function
Product *max(Product *itemArray, int len)
{
    //initialize first item as current max
    Product *max = &itemArray[0];
    for (int i = 1; i < len; ++i)
    {
        if (itemArray[i].cost > (*max).cost)
        {
            //get address of found max and assign to max
            max = &itemArray[i];
        }
    }

    return max;
}

void output(ostream &out, Product **shelf)
{
    //specify for 3 by 3 arrays only
    int len = 3;
    //spacing for each section
    const int spacing = 22;
    //spacing for line borders
    const int lineSpacing = (spacing * 6) + 1;
    out << setfill('-') << setw(lineSpacing) << "" << endl;
    out << setfill(' ');
    //loop row by row
    for (int i = 0; i < len; ++i)
    {
        int j = 0;
        //print decriptions
        out << left << setw(spacing) << "|Description: " << left << setw(spacing) << shelf[i][j].description;
        out << left << setw(spacing) << "|Description: " << left << setw(spacing) << shelf[i][j + 1].description;
        out << left << setw(spacing) << "|Description: " << left << setw(spacing) << shelf[i][j + 2].description << "|" << endl;
        //print part numbers
        out << left << setw(spacing) << "|Part Num: " << left << setw(spacing) << shelf[i][j].partNum;
        out << left << setw(spacing) << "|Part Num: " << left << setw(spacing) << shelf[i][j + 1].partNum;
        out << left << setw(spacing) << "|Part Num: " << left << setw(spacing) << shelf[i][j + 2].partNum << "|" << endl;
        //print costs
        out << left << setw(spacing) << "|cost: " << left << setw(spacing) << shelf[i][j].cost;
        out << left << setw(spacing) << "|cost: " << left << setw(spacing) << shelf[i][j + 1].cost;
        out << left << setw(spacing) << "|cost: " << left << setw(spacing) << shelf[i][j + 2].cost << "|" << endl;
        out << setfill('-') << setw(lineSpacing) << "" << endl;
        out << setfill(' ');
        //end printing if stream failure
        if (out.fail())
        {
            cout << "stream failure in output" << endl;
            return;
        }
    }
}

int main()
{
    int len = 5, partNum;
    double cost;
    string description;
    Product *items = new Product[len];
    Product item;
    string title;

    //populate items array
    cout << "In Screen Shot, Populated items array with entries:" << endl;
    cout << "phone 987 199.99\n"
         << "water bottle 345 4.99\n"
         << "computer mouse 678 23.79\n"
         << "calculator 658 50.54\n"
         << "headphones 678 17.88\n " << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "Item " << i + 1 << endl;
        cout << "Enter item description: ";
        getline(cin, description);
        cout << "Enter item part number: ";
        cin >> partNum;
        cout << "Enter item cost: ";
        cin >> cost;
        //set item properties
        item.description = description;
        item.partNum = partNum;
        item.cost = cost;
        //save item
        items[i] = item;
        cin.ignore();
    }
    cout << endl;
    //testing print function
    title = "Testing Print and Maximum";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    cout << "---Printing Current Test Bench (from user input, list of items):" << endl;
    print(items, len);
    cout << endl;
    cout << "---Testing found maximum function with current test bench" << endl;
    cout << "Found Maximum:" << endl;

    //testing maximum function
    Product *maximum = max(items, len);
    (*maximum).print();
    cout << endl;
    cout << "looping through array and asserting foundMax.cost >= currentItem.cost" << endl;
    for (int i = 0; i < len; i++)
    {
        assert((maximum->cost) >= items[i].cost);
        if ((maximum->cost) == items[i].cost)
        {
            cout << "found maximum cost: $" << maximum->cost << " == current item cost: $" << items[i].cost << endl;
        }
        else
        {
            cout << "found maximum cost: $" << maximum->cost << " > current item cost: $" << items[i].cost << endl;
        }
    }
    cout << "Passed maximum test" << endl;
    cout << endl;
    //Testing 3 x 3 dimensional array

    title = "Testing Print for 3 x 3 array";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    cout << endl;
    cout << "In Screenshot, Populated  multidimensional array with entries:" << endl;
    cout << "book 21007 17.99\n"
         << "phone 24100 567.99\n"
         << "calculator  34600 30.99\n"
         << "charging cable 21400 2.87 \n"
         << "camera 314600 656.99\n"
         << "Apple airpods 31700 150.99\n"
         << "laptop stand 20400 25.88\n"
         << "lamp 10300 30.99\n"
         << "computer keyboard 10400 26.99" << endl;
    cout << endl;

    len = 3;
    //populate multidimensional array
    Product **shelf = new Product *[len];
    for (int i = 0; i < len; ++i)
    {
        shelf[i] = new Product[len];
        cout << "shelf: " << i + 1 << endl;

        for (int j = 0; j < len; j++)
        {
            cout << "Item " << j + 1 << endl;
            cout << "Enter item description: ";
            getline(cin, description);
            cout << "Enter item part number: ";
            cin >> partNum;
            cout << "Enter item cost: ";
            cin >> cost;
            //set item properties
            item.description = description;
            item.partNum = partNum;
            item.cost = cost;
            //save item
            shelf[i][j] = item;
            cin.ignore();
        }
    }

    ostringstream out;
    ofstream outf;
    outf.open("table.txt");

    //output to file
    cout << "outputting to file" << endl;
    if (!outf.is_open())
    {
        cout << "failure opening" << endl;
    }

    output(outf, shelf);
    outf.close();

    cout << "outputting to terminal:" << endl;
    cout << endl;
    //ouput to terminal
    output(out, shelf);
    cout << out.str() << endl;

    //memory deallocation
    for (int i = 0; i < len; ++i)
    {
        delete[] shelf[i];
    }

    delete[] shelf;
    delete[] items;

    return 0;
}