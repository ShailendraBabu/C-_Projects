#include <iostream>
using namespace std;

bool areAnagrams(const char s1[], const char s2[], int len1, int len2)
{
    if (len1 != len2)
        return false;

    int freq[256] = {0};

    for (int i = 0; i < len1; i++)
    {
        freq[(unsigned char)s1[i]]++;
        freq[(unsigned char)s2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
            return false;
    }

    return true; // Corrected: return true if all frequencies are zero
}

int main()
{
    char s1[] = "listen";
    char s2[] = "silent";

    int len1 = sizeof(s1) / sizeof(s1[0]) - 1;
    int len2 = sizeof(s2) / sizeof(s2[0]) - 1;

    cout << (areAnagrams(s1, s2, len1, len2) ? "Anagrams" : "Not Anagrams");
    return 0;
}