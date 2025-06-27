#include <iostream>
#include <unordered_map>

using namespace std;

void findDuplicates(string str)
{
    unordered_map<char, int> frequencyMap;

    for (char ch : str)
        frequencyMap[ch]++;
    cout << "Duplicates: \n";

    for (auto &[ch, count] : frequencyMap)
    {
        if (count > 1)
        {
            cout << ch << " appears " << count << " times\n";
        }
    }
}

int main()
{
    string s = "programming";
    findDuplicates(s);
    return 0;
}