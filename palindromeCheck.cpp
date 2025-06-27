// simple c++ function that checks whether a given string is a palindrome or not ignoring spaces, punctuation and case sensitivity

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(const string &input)
{
    string cleaned;

    for (char ch : input)
    {
        if (isalnum(ch))
        {
            cleaned += tolower(ch); // Convert to lowercase and add to cleaned string
        }
    }

    int left = 0;
    int right = cleaned.length() - 1;

    while (left < right)
    {
        if (cleaned[left] != cleaned[right])
        {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // Is a palindrome
}

int main()
{
    std::string str = "pulu";

    if (isPalindrome(str))
    {
        std::cout << "The string is a palindrome.\n";
    }
    else
    {
        std::cout << "The string is not a palindrome.\n";
    }

    return 0;
}