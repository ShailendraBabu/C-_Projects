#include <iostream>
#include <string>
#include <memory> // For smart pointers

using namespace std;

class Toy
{
public:
    virtual string makeToy() const = 0; // Pure virtual function
    virtual ~Toy() {}
};

class BasicToy : public Toy
{
public:
    string makeToy() const override
    {
        return "Basic Toy";
    }
};

class ToyDecorator : public Toy
{
protected:
    unique_ptr<Toy> toy;

public:
    ToyDecorator(unique_ptr<Toy> t) : toy(move(t)) {}
};

class MusicToy : public ToyDecorator
{
public:
    MusicToy(unique_ptr<Toy> t) : ToyDecorator(move(t)) {}

    string makeToy() const override
    {
        return toy->makeToy() + " with Music";
    }
};

class LightToy : public ToyDecorator
{
public:
    LightToy(unique_ptr<Toy> t) : ToyDecorator(move(t)) {}

    string makeToy() const override
    {
        return toy->makeToy() + " with Lights";
    }
};

class VoiceToy : public ToyDecorator
{
public:
    VoiceToy(unique_ptr<Toy> t) : ToyDecorator(move(t)) {}

    string makeToy() const override
    {
        return toy->makeToy() + " with Voice";
    }
};

int main()
{
    unique_ptr<Toy> toy1 = make_unique<LightToy>(make_unique<MusicToy>(make_unique<BasicToy>()));
    cout << toy1->makeToy() << endl; // Output: Basic Toy with Music with Lights

    unique_ptr<Toy> toy2 = make_unique<VoiceToy>(make_unique<LightToy>(make_unique<BasicToy>()));
    cout << toy2->makeToy() << endl; // Output: Basic Toy with Lights with Voice

    unique_ptr<Toy> toy3 = make_unique<MusicToy>(make_unique<VoiceToy>(make_unique<BasicToy>()));
    cout << toy3->makeToy() << endl; // Output: Basic Toy with Voice with Music

    return 0;
}