#include <iostream>
#include <vector>
#include <string>

using namespace std;

int firstNonRepeatedCharacter(string s)
{
    vector<int> count(26, 0);
    for (char c : s)
        count[c - 'a']++;
    for (int i = 0; i < s.size(); ++i)
        if (count[s[i] - 'a'] == 1)
            return i;
    return -1;
}

int main()
{
    string s = "leetcodel";
    cout << "First unique char index: " << firstNonRepeatedCharacter(s) << endl;
    return 0;
}