#include <iostream>
using namespace std;

int strLength(char str[])
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    char a[] = "Bhavya";
    cout << strLength(a);

    return 0;
}