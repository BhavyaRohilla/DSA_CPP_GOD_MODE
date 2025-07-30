#include <iostream>
using namespace std;

// Manual String Copy
void strCopy(char dest[], const char source[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

// Manual String Compare
int stringCompare(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    { // ✅ fixed line
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i]; // Check remaining characters (if one is longer)
}

void changeCase(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // Convert uppercase to lowercase
            str[i] = str[i] + 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Convert lowercase to uppercase
            str[i] = str[i] - 32;
        }
        i++;
    }
}

int main()
{
    /*
    char source[] = "Bhavya";
    char destination[100];

    // Copy string
    strCopy(destination, source);
    cout << "Copied String => " << destination << endl;

    // Compare strings
    char str2[] = "BhavyaA";
    int result = stringCompare(source, str2);

    if (result == 0)
        cout << "Strings are equal" << endl;
    else if (result > 0)
        cout << "Source is greater than str2" << endl;
    else
        cout << "Source is less than str2" << endl;
*/

    char str[] = "BhAvYa123";
    cout << "Original String: " << str << endl;
    changeCase(str);
    cout << "Case Changed String: " << str << endl;

    return 0;
}
