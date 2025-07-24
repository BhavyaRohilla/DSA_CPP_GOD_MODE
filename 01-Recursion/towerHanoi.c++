#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);                                   // move n-1 from A to B using C
        cout << "Move disk from " << A << " to " << C << endl; // move nth disk from A to C
        TOH(n - 1, B, A, C);                                   // move n-1 from B to C using A
    }
}

int main()
{
    int n = 3;
    TOH(n, 1, 2, 3);
    return 0;
}
