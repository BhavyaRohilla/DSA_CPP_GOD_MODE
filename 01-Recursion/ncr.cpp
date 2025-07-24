#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    cout << nCr(5, 1);
    return 0;
}