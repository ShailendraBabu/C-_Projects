#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int z)
{
    int x = 0, y = arr.size() - 1;
    while (x < y)
    {
        int sum = arr[x] + arr[y];
        if (sum == z)
            return true;
        else if (sum < z)
            x++;
        else
            y--;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 11;
    cout << twoSum(arr, x);
}
