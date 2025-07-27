#include <iostream>
using namespace std;

int findingMissingElement(int arr[], int n)
{
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        arrSum += arr[i];
    }

    return totalSum - arrSum;
}

void findingMultipleMissingSorted(int arr[], int size)
{
    int diff = arr[0] - 0;

    for (int i = 0; i < size; i++)
        while (arr[i] - i > diff)
        {
            cout << "Missing : " << i + diff << endl;
            diff++;
        }
}

void findMultipleMissingUnsorted(int arr[], int size, int maxVal)
{
    int hash[maxVal + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]] = 1;
    }

    for (int i = 1; i <= maxVal; i++)
    {
        if (hash[i] == 0)
            cout << "Missing ==>> " << i << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6; // range 1 to 6, so size should be n - 1
    cout << "Missing number is => " << findingMissingElement(arr, n) << endl;
    int arr1[] = {2, 3, 5, 8, 9, 10};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    findingMultipleMissingSorted(arr1, size);
    int arr2[] = {3, 7, 1, 2, 8, 4, 5};
    int size1 = sizeof(arr2) / sizeof(arr[0]);
    int maxVal = 8;

    findMultipleMissingUnsorted(arr2, size1, maxVal);
    return 0;
}