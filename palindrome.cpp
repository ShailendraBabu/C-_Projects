#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome2Pointer(const string &s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

bool isPalindromeReverseAndCompare(const string &s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

bool isPalindromeNumber(int num)
{
    int original = num, reversed = 0;
    while (num > 0)
    {
        reversed = (reversed * 10) + (num % 10);
        num /= 10;
    }
    return original == reversed;
}

bool isPalindromeNonAlphanegate(const string &s)
{
    string clean;
    for (char c : s)
    {
        if (!isalnum(c))
            clean += tolower(c);
    }
    int left = 0, right = clean.size() - 1;
    while (left < right)
    {
        if (clean[left++] != clean[right--])
            return false;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter a string:" << endl;
    cin >> str;
    cout << (isPalindrome2Pointer(str) ? "Palindrome" : "Not Palindrome") << endl;
    cout << (isPalindromeNonAlphanegate(str) ? "Palindrome" : "Not Palindrome") << endl;
    cout << (isPalindromeReverseAndCompare(str) ? "Palindrome" : "Not Palindrome") << endl;
}