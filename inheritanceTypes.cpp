#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Vehicle
{
    publlic : string brand;
    int year;

    Vehicle(string b, int y) : brand(b), year(y)
    {
        cout << "Vehicle constructor called for " << brand << "( " << year << " )" << endl;
    }

    void displayInfo()
    {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }

    void startEngine()
    {
        cout << "Starting cars engine..." << endl;
    }

    virtual void honk()
    {
        cout << "Car honking beeeeeeeeeeeeeeep!" << endl;
    }

    virtual ~Vehicle()
    {
        cout << "Vehicle destructor called for " << brand << endl;
    }
};

// Single Inheritance

class Car : public Vehicle
{
public:
    int noOfDoors;

    Car(string b, int y, int nd) : Vehicle(b, y), noOfDoors(nd)
    {
        cout << "Car constructor called for " << brand << " with " << noOfDoors << " doors." << endl;
    }

    void drive() const
    {
        cout << brand << " car is being driven...." << endl;
    }

    void honk() override
    {
        cout << brand << " car honking beep beep!" << endl;
    }

    ~Car() override
    {
        cout << "Car destructor called for " << brand << endl;
    }
};

class SportsCar : public Car
{
public:
    int topSpeed;

    SportsCar(string b, int y, int nd, int ts) : Car(b, y, nd), topSpeed(ts)
    {
        cout << "SportsCar constructor called for " << brand << " with top speed of " << topSpeed << " km/h." << endl;
    }

    void race() const
    {
        cout << brand << " sports car is racing at " << topSpeed << " km/h!" << endl;
    }

    virtual void honk() override
    {
        cout << brand << " sports car honking vroom vroom!" << endl;
    }

    ~SportsCar() override
    {
        cout << "SportsCar destructor called for " << brand << endl;
    }
};

// Hierarchical Inheritance

class Bike : public Vehicle
{
public:
    bool hasCarrier;

    Bike(string b, int y, bool hc) : Vehicle(b, y), hasCarrier(hc)
    {
        cout << "Bike constructor called for " << brand << " with carrier: " << (hasCarrier ? "Yes" : "No") << endl;
    }

    void wheelie() const
    {
        cout << brand << " bike is doing a wheelie!" << endl;
    }

    void honk() override
    {
        cout << brand << " bike honking beep beep!" << endl;
    }

    ~Bike() override
    {
        cout << "Bike destructor called for " << brand << endl;
    }
};

class Truck : public Vehicle
{
public:
    double loadCapacity;

    Truck(string b, int y, int lc) : Vehicle(b, y), loadCapacity(lc)
    {
        cout << "Truck constructor called for " << brand << " with load capacity of " << loadCapacity << " tons." << endl;
    }

    void haul() const
    {
        cout << brand << " truck is hauling a load!" << endl;
    }

    void honk() override
    {
        cout << brand << " truck honking honk honk!" << endl;
    }

    ~Truck() override
    {
        cout << "Truck destructor called for " << brand << endl;
    }
};

class Swimmer
{
public:
    Swimmer()
    {
        cout << "Swimmer constructor called." << endl;
    }

    void swim() const
    {
        cout << "Swimming..." << endl;
    }

    virtual ~Swimmer()
    {
        cout << "Swimmer destructor called." << endl;
    }
};