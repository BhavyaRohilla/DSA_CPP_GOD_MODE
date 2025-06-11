#include <iostream>
using namespace std;

int main()
{
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int c[10] = {2, 4, 6};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(E) / sizeof(E[0]);
    for (int i = 0; i < size; i++)
    {
        cout << &E[i] << endl;
    }

    cout << E[2] << endl;
    cout << 2 [E] << endl;
    cout << *(E + 2) << endl;

    return 0;
}