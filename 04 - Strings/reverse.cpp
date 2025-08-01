#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end)
    {
        // Swap chracter
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{

    char str[100];
    cout << "String daal bhai => ";
    cin.getline(str, 100);

    reverseString(str);
    cout << "Reversed string: " << str << endl;

    return 0;
}