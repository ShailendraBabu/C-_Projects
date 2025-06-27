#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find two indices such that their values add up to the target

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map; // Map to store the value and its index

    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i]; // Calculate the difference needed to reach the target
        if (map.count(diff))         // Check if the difference exists in the map
        {
            return {map[diff], i}; // Return the indices if found
        }
        map[nums[i]] = i; // Store the current number and its index in the map
    }
    return {}; // Return an empty vector if no solution is found
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices found: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}
