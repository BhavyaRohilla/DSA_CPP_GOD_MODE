#include <iostream>
#include <unordered_map>
using namespace std;

void findDuplicatesSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            int count = 1;
            while (i + 1 < n && arr[i] == arr[i + 1])
            {
                count++;
                i++;
            }
            cout << "Duplicate: " << arr[i] << " appears " << count << " times" << endl;
        }
    }
}

void findDuplicatesUnsorted(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (auto element : freq)
    {
        if (element.second > 1)
            cout << "Duplicate: " << element.first << " appears " << element.second << " times" << endl;
    }
}

int main()
{
    // int arr[] = {2, 3, 3, 3, 4, 4, 5, 6, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // findDuplicatesSorted(arr, n);

    int arr[] = {3, 5, 2, 3, 6, 2, 5, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    findDuplicatesUnsorted(arr, n);
    return 0;
}