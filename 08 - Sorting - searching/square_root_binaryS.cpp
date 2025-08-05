#include <iostream>
using namespace std;

int squareRoot(int x)
{
    int start = 0, end = x;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid = x / mid)
            return mid;
        if (mid > x / mid)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end;
}

int main()
{
    int n;
    cout << "Enter the number => " << endl;
    cin >> n;
    int ans = squareRoot(n);

    int precision;
    cout << "Enter the number of floating digit in precision => " << endl;
    cin >> precision;

    double step = 0.1;
    double finalAns = ans;
    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * j <= n; j += step)
            finalAns = j;
        step /= 10;
    }

    cout << "Final ans is => " << finalAns << endl;

    return 0;
}