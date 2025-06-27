#include <iostream>

using namespace std;

int strstr(const char haystack[], int hlen, const char needle[], int nlen)
{
    if (nlen == 0)
        return 0;

    for (int i = 0; i <= hlen - nlen; i++)
    {
        bool match = true;
        for (int j = 0; j < nlen; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return i;
    }
    return -1;
}

int main()
{
    char haystack[] = "hello";
    char needle[] = "ll";

    int hlen = sizeof(haystack) / sizeof(haystack[0]) - 1;
    int nlen = sizeof(needle) / sizeof(needle[0]) - 1;

    cout << "First occurence: " << strstr(haystack, hlen, needle, nlen);
    return 0;
}