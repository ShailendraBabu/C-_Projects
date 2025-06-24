#include <iostream>
#include <string>
#include <memory> // For smart pointers

// ---------- Shape Interface ----------
class Shape
{
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}
};

// ---------- Circle Class ----------
class Circle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing a Circle.\n";
    }
};

// ---------- Rectangle Class ----------
class Rectangle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing a Rectangle.\n";
    }
};

// ---------- Triangle Class ----------
class Triangle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing a Triangle.\n";
    }
};

// ---------- ShapeFactory ----------
class ShapeFactory
{
public:
    std::unique_ptr<Shape> createShape(const std::string &shapeType)
    {
        if (shapeType == "circle")
        {
            return std::make_unique<Circle>();
        }
        else if (shapeType == "rectangle")
        {
            return std::make_unique<Rectangle>();
        }
        else if (shapeType == "triangle")
        {
            return std::make_unique<Triangle>();
        }
        else
        {
            return nullptr;
        }
    }
};

// ---------- Main ----------
int main()
{
    ShapeFactory factory;

    auto shape1 = factory.createShape("circle");
    if (shape1)
        shape1->draw();

    auto shape2 = factory.createShape("rectangle");
    if (shape2)
        shape2->draw();

    auto shape3 = factory.createShape("triangle");
    if (shape3)
        shape3->draw();

    auto shape4 = factory.createShape("hexagon");
    if (!shape4)
        std::cout << "Unknown shape type!\n";

    return 0;
}
