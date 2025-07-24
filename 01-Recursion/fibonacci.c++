#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &memo)
{
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    return memo[n];
}

int fib1(int n)
{
    if (n <= 1)
        return n;
    return fib1(n - 2) + fib1(n - 1);
}

int main()
{
    vector<int> memo(5 + 1, -1);
    cout << fib1(5) << endl;
    cout << fibonacci(5, memo);
}