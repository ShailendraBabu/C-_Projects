// C++ program to find the first missing positive number
// using visited array

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr)
{
    int n = arr.size();

    // To mark the occurrence of elements
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {

        // if element is in range from 1 to n
        // then mark it as visited
        if (arr[i] > 0 && arr[i] <= n)
            vis[arr[i] - 1] = true;
    }

    // Find the first element which is unvisited
    // in the original array
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i - 1])
        {
            return i;
        }
    }

    // if all elements from 1 to n are visited
    // then n + 1 will be first positive missing number
    return n + 1;
}

int main()
{

    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
}