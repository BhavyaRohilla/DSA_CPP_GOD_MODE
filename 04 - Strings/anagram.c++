#include <iostream>
#include <cstring>
using namespace std;

bool isAnagram(const char str1[], const char str2[])
{
    int freq[256] = {0};

    // count chracter in str1
    for (int i = 0; str1[i] != '\0'; i++)
    {
        char ch = str1[i];
        if (ch != ' ')
            freq[tolower(ch)]++;
    }

    // Subtract characters in str2
    for (int i = 0; str2[i] != '\0'; i++)
    {
        char ch = str2[i];
        if (ch != ' ')
            freq[tolower(ch)]--;
    }

    // Check if all frequencies are 0
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
            return false;
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

    if (isAnagram(str1, str2))
        cout << "Yes, both are anagrams." << endl;
    else
        cout << "No, not anagrams." << endl;
    return 0;
}