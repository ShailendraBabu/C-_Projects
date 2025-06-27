#include <iostream>
#include <string>
#include <climits>

using namespace std;

int convertStringToInt(string s)
{
    int i = 0, sign = 1, result = 0;
    while (s[i] == ' ')
        i++;
    if (s[i] == '+' || s[i] == '-')
        sign = (s[i++] == '-') ? -1 : 1;
    while (isdigit(s[i]))
    {
        if (result > (INT_MAX - (s[i] - '0')) / 10)
            return sign == 1 ? INT_MAX : INT_MIN;
        result = result * 10 + (s[i++] - '0');
    }
    return result * sign;
}

int main()
{
    string s = "109143";
    cout << "Converted number: " << convertStringToInt(s) << endl;
    return 0;
}