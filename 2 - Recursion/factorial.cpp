#include <iostream>
using namespace std;

int fact(int n)
{
    if (n < 0)
    {
        cout << "Error: Factorial of a negative number is not defined!" << endl;
        return -1; // error code
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = fact(num);

    if (result != -1) // if no error
        cout << "Factorial = " << result << endl;

    return 0;
}
