#include <iostream>
using namespace std;

int main()
{
    char name[10] = "Bhavya";
    char name2[] = {'B', 'h', 'a', 'v', 'y', 'a', '\0'};
    cout << name << " => " << name2 << endl;

    char name3[100];

    cout << "Enter the name (no spaces) => ";
    cin >> name3;
    cout << "You entered => " << name3 << endl;

    // For intput with spaces (use cin.getline)
    cout << "Enter full name (with spaces) => ";
    cin.ignore(); // clear input buffer
    cin.getline(name3, 100);
    cout << "Full name => " << name3 << endl;
    return 0;
}