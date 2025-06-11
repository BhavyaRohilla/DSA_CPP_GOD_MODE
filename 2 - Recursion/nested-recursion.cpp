#include <iostream>
using namespace std;

int funA(int n)
{
    if (n > 100)
        return n - 10;

    return funA(funA(n + 11));
}

int main()
{
    cout << funA(95) << endl;
    return 0;
}