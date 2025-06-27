#include <iostream>

// Old interface (incompatible with new system)
class OldPrinter
{
public:
    void oldPrint()
    {
        std::cout << "Using Old Printer Interface\n";
    }
};

// New interface expected by the modern client
class NewPrinter
{
public:
    virtual void print() = 0; // Pure virtual function
    virtual ~NewPrinter() {}  // Virtual destructor for safety
};

// Adapter class: makes OldPrinter compatible with NewPrinter interface
class PrinterAdapter : public NewPrinter
{
    OldPrinter *oldPrinter;

public:
    // Constructor takes a pointer to OldPrinter
    PrinterAdapter(OldPrinter *printer) : oldPrinter(printer) {}

    // Override the new interface and delegate to oldPrint()
    void print() override
    {
        oldPrinter->oldPrint(); // Call the legacy method
    }
};

int main()
{
    // Step 1: Create an instance of the old class
    OldPrinter *old = new OldPrinter();

    // Step 2: Use the adapter to wrap it
    NewPrinter *adapted = new PrinterAdapter(old);

    // Step 3: Use the new interface, which internally calls oldPrint()
    adapted->print();

    // Cleanup
    delete old;
    delete adapted;

    return 0;
}