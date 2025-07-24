#include <iostream>
using namespace std;

// 🌐 Global variable: accumulates the sum during recursion
int globalSum = 0;

/*
🌍 sumWithGlobalAccumulator(int n)
-----------------------------------
Recursively adds numbers from 'n' down to 1
and stores the total in the global variable `globalSum`.

⚠️ Global variables retain state even after function finishes.
Best for understanding side effects, but not good for production unless necessary.
*/
void sumWithGlobalAccumulator(int n)
{
    if (n > 0)
    {
        globalSum += n;                  // Add current number to global sum
        sumWithGlobalAccumulator(n - 1); // Recurse with n-1
    }
}

/*
🧽 resetGlobal()
-----------------
Utility function to reset globalSum back to 0.
Useful when calling the recursive function multiple times.
*/
void resetGlobal()
{
    globalSum = 0;
}

int main()
{
    int num = 5;

    // First calculation
    sumWithGlobalAccumulator(num);
    cout << "🌐 Sum using global variable recursion for " << num << " is: " << globalSum << endl;

    // Reset and reuse
    resetGlobal();

    // Another calculation for demonstration
    num = 10;
    sumWithGlobalAccumulator(num);
    cout << "🌐 Sum using global variable recursion for " << num << " is: " << globalSum << endl;

    return 0;
}
