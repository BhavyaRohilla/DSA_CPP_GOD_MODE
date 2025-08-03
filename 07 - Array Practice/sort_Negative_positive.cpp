#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr)
{
    int l = 0;
    int h = arr.size() - 1;

    if (arr[l] < 0)
        l++;
    else if (arr[h] > 0)
        h--;
    else
        swap(arr[l], arr[h]);
}

int main()
{

    vector<int> arr{1, 3, -2, -7, -8, 4, 7, -12};
    sort(arr);
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
    return 0;
}