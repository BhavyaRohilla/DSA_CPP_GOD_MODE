#include <iostream>
using namespace std;

int pow1(int m, int n)
{
    if (n > 0)
    {
        return pow1(m, n - 1) * m;
    }
    return 1;
}

int pow2(int m, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return pow2(m * m, n / 2);
    return m * pow2(m * m, (n - 1) / 2);
}

int main()
{
    cout << pow1(2, 9) << endl;
    cout << pow2(2, 9);
    return 0;
}