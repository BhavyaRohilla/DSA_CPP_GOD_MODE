#include <iostream>
using namespace std;

void findDuplicates(const char str[])
{
    int freq[256] = {0}; // ASCII characters (0 to 255)

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = str[i];
        freq[ch]++;
    }

    // Print characters that occur more than once
    cout << "Duplicate characters are: ";
    bool found = false;
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 1)
        {
            cout << "'" << (char)i << "' ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
}

int main()
{
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    findDuplicates(str);

    return 0;
}
