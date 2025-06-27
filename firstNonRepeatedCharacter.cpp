#include <iostream>
#include <unordered_map>

using namespace std;

char firstNonRepeatedChar(string s)
{
    unordered_map<char, int> frequency;

    for (char c : s)
        frequency[c]++;

    for (char c : s)
    {
        if (frequency[c] == 1)
            return c;
    }
    return '\0';
}

int main()
{
    string s = "swissingg";
    char result = firstNonRepeatedChar(s);
    if (result != 0)
        cout << "First non-repeated character: " << result << endl;
    else
        cout << "No unique character found";
}
