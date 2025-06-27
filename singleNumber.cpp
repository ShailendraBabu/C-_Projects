#include <iostream>
#include <vector>
using namespace std;

// Function to find the number that appears only once
int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int num : nums)
    {
        result ^= num; // XOR cancels duplicates
    }
    return result;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number: " << singleNumber(nums) << endl;
    return 0;
}
