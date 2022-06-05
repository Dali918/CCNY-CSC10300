#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
//Base class computer
class Computer
{
public:
    //Constructor
    Computer(string CPU, double speed, double price, int RAM, int storage)
    {
        this->CPU = CPU;
        this->clockSpeed = speed;
        this->price = price;
        this->RAM = RAM;
        this->storage = storage;
    }
    string getCPUtype() const { return this->CPU; }
    int getRAM() const { return this->RAM; };
    int getStorage() const { return this->storage; };
    double getClockSpeed() const { return this->clockSpeed; };
    double getPrice() const { return this->price; };
    virtual void print() const;
    //setters
    void setCPUtype(string cpu);
    void setRAM(int ram);
    void setStorage(int storage);
    void setClockSpeed(double speed);
    void setPrice(double price);

private:
    string CPU;
    double clockSpeed, price;
    int RAM, storage;
};
//types of computer
class Desktop : public Computer
{
public:
    //Constructors
    Desktop();
    Desktop(string CPU, double speed, double price, int RAM, int storage, int towersize, int warrant, double psu) : Computer{CPU, speed, price, RAM, storage}, towerSize{towersize}, warranty{warrant}, PSU{psu} {}

    int getTowerSize() const { return this->towerSize; }
    int getWarranty() const { return this->warranty; }
    double getPSU() const { return this->PSU; }

    void setTowerSize(int size) { this->towerSize = size; }
    void setWarranty(int warrant) { this->warranty = warrant; }
    void setPSU(double psu) { this->PSU = psu; }

    void print() const override;

private:
    int towerSize, warranty;
    double PSU;
};

class Laptop : public Computer
{
public:
    //Constructors
    Laptop();
    Laptop(string CPU, double speed, double price, int RAM, int storage, double battery, double i_weight, double screen) : Computer{CPU, speed, price, RAM, storage}, batteryLife{battery}, weight{i_weight}, screenSize{screen} {}

    double getBatteryLife() const { return this->batteryLife; }
    double getWeight() const { return this->weight; }
    double getScreenSize() const { return this->screenSize; }

    void setBatteryLife(double life) { this->batteryLife = life; }
    void setWeight(double weight) { this->weight = weight; }
    void setScreenSize(double size) { this->screenSize - size; }

    void print() const override;

private:
    double batteryLife, weight, screenSize;
};
//types of desktop
class Dell : public Desktop
{
public:
    //Constructors
    Dell();
    Dell(string CPU, double speed, double price, int RAM, int storage, int towersize, int warrant, double psu, string model) : Desktop{CPU, speed, price, RAM, storage, towersize, warrant, psu}, modelType{model} {}
    void setModelType(string type) { this->modelType = type; }
    string getModelType() const { return this->modelType; }
    void print() const override;

private:
    string modelType;
};

class HP : public Desktop
{
public:
    //Constructors
    HP();
    HP(string CPU, double speed, double price, int RAM, int storage, int towersize, int warrant, double psu, string model) : Desktop{CPU, speed, price, RAM, storage, towersize, warrant, psu}, modelType{model} {}
    void setModelType(string type) { this->modelType = type; }
    string getModelType() const { return this->modelType; }
    void print() const override;

private:
    string modelType;
};
//types of laptop
class Apple : public Laptop
{
public:
    Apple();
    Apple(string CPU, double speed, double price, int RAM, int storage, double battery, double i_weight, double screen, string make) : Laptop{CPU, speed, price, RAM, storage, battery, i_weight, screen}, makeType{make} {}
    void setMakeType(string type) { this->makeType = type; }
    string getMakeType() const { return this->makeType; }
    void print() const override;

private:
    string makeType;
};

class Lenovo : public Laptop
{
public:
    Lenovo();
    Lenovo(string CPU, double speed, double price, int RAM, int storage, double battery, double i_weight, double screen, string make) : Laptop{CPU, speed, price, RAM, storage, battery, i_weight, screen}, makeType{make} {}
    void setMakeType(string type) { this->makeType = type; }
    string getMakeType() const { return this->makeType; }
    void print() const override;

private:
    string makeType;
};

//Print Functions
void Computer::print() const
{
    cout << left << setw(14) << "CPU Type: " << getCPUtype() << endl;
    cout << left << setw(14) << "RAM: " << getRAM() << " GB" << endl;
    cout << left << setw(14) << "Storage: " << getStorage() << " GB" << endl;
    cout << left << setw(14) << "Clock Speed: " << fixed << setprecision(2) << getClockSpeed() << " GHZ" << endl;
    cout << left << setw(14) << "Price: "
         << "$" << fixed << setprecision(2) << getPrice() << endl;
}

void Desktop::print() const
{
    Computer::print();
    cout << left << setw(14) << "Tower Size: " << this->getTowerSize() << "\"" << endl;
    cout << left << setw(14) << "Warranty: " << this->getWarranty() << " years" << endl;
    cout << left << setw(14) << "PSU Wattage: " << this->getPSU() << " Watts (W)" << endl;
}
void Laptop::print() const
{
    Computer::print();
    cout << left << setw(14) << "Screen Size: " << this->getScreenSize() << "\"" << endl;
    cout << left << setw(14) << "Weight: " << this->getWeight() << " kg" << endl;
    cout << left << setw(14) << "Battery Life: " << this->getBatteryLife() << " hrs" << endl;
}
void Dell::print() const
{
    Desktop::print();
    cout << left << setw(14) << "Model Type: " << this->getModelType() << endl;
}
void HP::print() const
{
    Desktop::print();
    cout << left << setw(14) << "Model Type: " << this->getModelType() << endl;
}
void Apple::print() const
{
    Laptop::print();
    cout << left << setw(14) << "Make Type: " << this->getMakeType() << endl;
}
void Lenovo::print() const
{
    Laptop::print();
    cout << left << setw(14) << "Make Type: " << this->getMakeType() << endl;
}

int main()
{
    string title = "TESTING DERIVED CLASSES";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    cout << "---Making Vector of type Computer* " << endl;
    cout << "Test Bench:" << endl;
    //DELL
    cout << "Dell :" << endl;
    cout << "CPU type: i3-10105, clock speed: 3.7, price: $638.99, RAM: 12GB, Storage: 900GB" << endl;
    cout << "Tower Size: 14\", Warranty: 6 years, PSU: 1800 Watts, Model Type: Dell Inspiron Desktop" << endl;
    //HP
    cout << "HP :" << endl;
    cout << "CPU type: i5-8100, clock speed: 2.7, price: $526.99, RAM: 8GB, Storage: 956GB" << endl;
    cout << "Tower Size: 12\", Warranty: 4 years, PSU: 1500 Watts, Model Type: HP Desktop - 190-0302in\n"
         << endl;
    //LENOVO
    cout << "Lenovo :" << endl;
    cout << "CPU type: i7-1135G7, clock speed: 3.4, price: $949.00, RAM: 8GB, Storage: 256GB" << endl;
    cout << "Battery Life: 10 hours\", Weight: 1.36 kg, Sceen Size: 13.3\", Model Type: Lenovo Thinkpad L13 Yoga\n"
         << endl;
    //APPLE
    cout << "Apple :" << endl;
    cout << "CPU type: M1, clock speed: 3.2, price: $1499.00, RAM: 8GB, Storage: 256G" << endl;
    cout << "Battery Life: 20 hours\", Weight: 1.4 kg, Sceen Size: 13\", Model Type: Apple MacBook Pro 13\n"
         << endl;
    cout << endl;

    cout << "---Making Computer Vector with different computer subclasses:" << endl;
    cout << "--- Printing Computer Vector" << endl;

    //making computers vector
    vector<Computer *> computers;
    Dell dell("i3-10105", 3.7, 638.99, 12, 900, 14, 6, 1800, "Dell Inspiron Desktop");
    HP hp("i5-8100", 2.7, 526.99, 8, 956, 12, 4, 1500, "HP Desktop - 190-0302in");
    Lenovo lenovo("i7-1135G7", 3.4, 949.00, 8, 256, 10, 1.36, 13.3, "Lenovo Thinkpad L13 Yoga");
    Apple macbook("M1", 3.2, 1499.00, 16, 512, 20, 1.4, 13, "Apple MacBook Pro 13\"");

    computers.push_back(&dell);
    computers.push_back(&hp);
    computers.push_back(&lenovo);
    computers.push_back(&macbook);
    //printing vectors
    for (Computer *elem : computers)
    {

        elem->print();
        cout << endl;
    }

    return 0;
}