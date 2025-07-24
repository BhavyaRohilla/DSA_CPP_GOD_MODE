#include <iostream>
using namespace std;

int sumNatural(int n)
{
    if (n > 0)
    {
        return sumNatural(n - 1) + n;
    }
    return 0;
}

int main()
{
    cout << sumNatural(10);
}