#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> count;

    vector<int> result;

    for (int num : nums1)
        count[num]++;

    for (int num : nums2)
    {
        if (count[num] > 0)
        {
            result.push_back(num);
            count[num]--; // Decrease count to avoid duplicates in result
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {3, 4, 5, 6, 7};

    vector<int> result = intersection(nums1, nums2);
    cout << "Intersection of two arrays: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;
}