#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point &p)
    {
        return Point(x + p.x, y + p.y);
    }

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point p1(1, 2), p2(4, 5);
    Point p3 = p1 + p2;
    p3.display();
}