#include <iostream>
#include <unordered_set>
using namespace std;

bool hasPairWithSum(int arr[], int n, int k)
{
    unordered_set<int> seen;

    for (int i = 0; i < n; ++i)
    {
        int complement = k - arr[i];
        if (seen.count(complement))
        {
            cout << "Pair found: (" << arr[i] << ", " << complement << ")\n";
            return true;
        }
        seen.insert(arr[i]);
    }

    cout << "No pair found with sum " << k << endl;
    return false;
}

int main()
{
    int arr[] = {10, 15, 3, 7};
    int k = 17;
    int n = sizeof(arr) / sizeof(arr[0]);

    hasPairWithSum(arr, n, k);
    return 0;
}
