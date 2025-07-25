#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = new int[5]{1, 2, 3, 4, 5}; // initialize directly

    for (int i = 0; i < 5; i++)
    {
        cout << "A => " << a[i] << "\n";
        cout << "P => " << p[i] << "\n";
    }

    delete[] p;

    return 0;
}
