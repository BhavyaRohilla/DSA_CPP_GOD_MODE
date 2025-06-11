#include <iostream>
using namespace std;

int main()
{

    // int n;
    // cin >> n;
    // int A[n]; // Valid in c++ // not a good practice

    int n;
    cin >> n;
    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }
    delete[] p;
}