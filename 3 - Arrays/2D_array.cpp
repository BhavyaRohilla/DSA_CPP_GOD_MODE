#include <iostream>
using namespace std;

int main()
{
    // ----------------------
    // ✅ Method 1: Static 2D Array
    // Memory is allocated on the stack
    // Fast access, but size must be known at compile time
    // ----------------------
    int A[3][4] = {
        {1, 2, 3, 4},
        {2, 4, 6, 8},
        {1, 3, 5, 7}};

    // ----------------------
    // ✅ Method 2: Array of Pointers (Dynamic Rows)
    // Each row is dynamically allocated
    // Good when number of rows is fixed but columns can be changed
    // ----------------------
    int *B[3];         // Array of 3 int pointers (on stack)
    B[0] = new int[4]; // Row 0
    B[1] = new int[4]; // Row 1
    B[2] = new int[4]; // Row 2

    // Optional: Initialize elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            B[i][j] = i + j; // Example values
        }
    }

    // ----------------------
    // ⚠️ Method 3: Double Pointer (Fully Dynamic 2D Array)
    // Allocate both rows and columns dynamically
    // Useful when both row and column sizes are decided at runtime
    // ----------------------
    int **C = new int *[3]; // Allocate 3 rows (array of int pointers)
    for (int i = 0; i < 3; i++)
    {
        C[i] = new int[4]; // Each row has 4 columns
    }

    // Optional: Initialize
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i][j] = i * j; // Example values
        }
    }

    // ----------------------
    // 🔁 Optional: Display to check values
    // ----------------------
    cout << "Static array A:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Dynamic array B:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Double pointer array C:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // ----------------------
    // 🧹 Clean up heap memory
    // ----------------------
    for (int i = 0; i < 3; i++)
    {
        delete[] B[i]; // delete each row of B
        delete[] C[i]; // delete each row of C
    }
    delete[] C; // delete the array of row pointers

    return 0;
}
