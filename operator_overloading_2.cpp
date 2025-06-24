#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Correct declaration: friend allows access to private members
    friend ostream &operator<<(ostream &os, const Point &p);
};

// Correct definition: return by reference, matches the declaration
ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    Point p1(1, 2);
    cout << p1 << endl; // Output: (1, 2)
}
