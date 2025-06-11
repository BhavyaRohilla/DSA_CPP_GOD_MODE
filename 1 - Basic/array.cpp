#include <iostream>
using namespace std;

int main()
{
    // 🧠 We're learning arrays in C++! Let's have some fun! 🎉

    // ❌ Not recommended: these lines show old or wrong ways
    // int a[5];             // You can do this, but values are garbage 🗑️
    // a[0] = 12;            // You'd have to assign each value one by one 😩
    // a[1] = 22;
    // a[2] = 25;

    // ❌ Also not recommended: arrays with size from user input
    // int n;
    // cout << "Enter the size => ";
    // cin >> n;
    // int a[n] = {2, 3, 4}; // ❗ This won't work in standard C++ 🚫

    // ✅ Recommended: create a fixed-size array with values 🧺
    int a[5] = {2, 3, 4}; // 🎯 The rest of the elements become 0 by default

    // 🌀 Let's print all elements using a range-based for loop
    for (int x : a)
    {
        cout << x << endl; // 🖨️ Print each value on a new line
    }

    // 🧪 Bonus: you could also check the total size of the array
    // cout << sizeof(a) << endl; // Shows total bytes used by the array

    // 🛠️ Another way to print (using index):
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << a[i] << endl;
    // }N

    // 🎉 That's it! You've just worked with arrays in C++! 🔥

    return 0; // 🚪 Exit the program
}
