#include <iostream>
using namespace std;

void fun1(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun1(n - 1); // recursive call to fun1
    }
}

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1); // recursive call to fun2
        cout << n << endl;
    }
}

int main()
{
    cout << "fun1 output:\n";
    fun1(3); // Output: 3 2 1 (decreasing order)

    cout << "\nfun2 output:\n";
    fun2(3); // Output: 1 2 3 (increasing order)

    return 0;
}
