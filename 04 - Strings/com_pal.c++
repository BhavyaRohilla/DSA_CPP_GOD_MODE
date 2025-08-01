#include <iostream>
#include <cstring>
using namespace std;

// Compare two strings manually
bool areStringsEqual(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

// Check if a string is a palindrome
bool isPalindrome(const char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    char str1[100], str2[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    // String Comparison
    if (areStringsEqual(str1, str2))
        cout << "Strings are equal!" << endl;
    else
        cout << "Strings are NOT equal!" << endl;

    // Palindrome Check
    if (isPalindrome(str1))
        cout << "First string is a Palindrome!" << endl;
    else
        cout << "First string is NOT a Palindrome!" << endl;

    if (isPalindrome(str2))
        cout << "Second string is a Palindrome!" << endl;
    else
        cout << "Second string is NOT a Palindrome!" << endl;

    return 0;
}
