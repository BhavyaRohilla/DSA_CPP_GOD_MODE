#include <iostream>
using namespace std;

int main()
{
    // Static 2D array
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Array of pointers (heap rows)
    int *b[3];
    b[0] = new int[4]{1, 2, 3, 4};
    b[1] = new int[4]{5, 6, 7, 8};
    b[2] = new int[4]{9, 10, 11, 12};

    // Pointer to pointer (fully dynamic 2D array)
    int **c = new int *[3];
    c[0] = new int[4]{1, 2, 3, 4};
    c[1] = new int[4]{5, 6, 7, 8};
    c[2] = new int[4]{9, 10, 11, 12};

    // Print to verify
    cout << "Array a:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            cout << a[i][j] << " ";
    cout << "\n\n";

    cout << "Array b:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            cout << b[i][j] << " ";
    cout << "\n\n";

    cout << "Array c:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            cout << c[i][j] << " ";
    cout << "\n";

    // Deallocate memory
    for (int i = 0; i < 3; ++i)
    {
        delete[] b[i];
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
