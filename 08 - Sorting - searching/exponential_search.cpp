#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int x)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int expSearch(vector<int> &arr, int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < arr.size() && arr[i] <= x)
    {
        i *= 2;
    }
    return binarySearch(arr, i / 2, min(i, (int)arr.size() - 1), x);
}

int main()
{
    vector<int> arr{3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int x = 13;
    int ans = expSearch(arr, x);
    cout << "Ans is => " << ans;
    return 0;
}