#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void printPermutations(string str)
{
    sort(str.begin(), str.end()); // Start from the smallest permutation
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    printPermutations(str);

    return 0;
}