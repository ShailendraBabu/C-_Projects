#include <iostream>
using namespace std;

int fibonacci_iterative(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i)
    {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int fibonacci_recursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    cout << "iterative Fibonacci(" << n << ")" << fibonacci_iterative(n) << endl;
    cout << "recursive Fibonacci(" << n << ")" << fibonacci_recursive(n) << endl;
    return 0;
}