#include <iostream>
using namespace std;

// Function to find min and max using pairwise comparison
void findMinMax(int arr[], int n, int &min, int &max)
{
    int i;

    // If array has even number of elements
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            max = arr[0];
            min = arr[1];
        }
        else
        {
            max = arr[1];
            min = arr[0];
        }
        i = 2; // Start from index 2
    }
    else
    {
        // If odd, initialize both min and max as first element
        max = min = arr[0];
        i = 1; // Start from index 1
    }

    // Compare in pairs
    while (i < n - 1)
    {
        int localMin, localMax;
        if (arr[i] > arr[i + 1])
        {
            localMax = arr[i];
            localMin = arr[i + 1];
        }
        else
        {
            localMax = arr[i + 1];
            localMin = arr[i];
        }

        if (localMax > max)
            max = localMax;
        if (localMin < min)
            min = localMin;

        i += 2; // Move to next pair
    }
}

int main()
{
    int arr[] = {7, 2, 9, 4, 1, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, n, min, max);

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    return 0;
}
