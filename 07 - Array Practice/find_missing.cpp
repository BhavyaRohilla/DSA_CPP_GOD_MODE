#include <iostream>
#include <vector>
using namespace std;

void findMissing(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]);
        if (arr[index - 1] > 0)
            arr[index - 1] *= -1;
    }
    // for (auto a : arr)
    // {
    //     cout << a << " ";
    // }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
            cout << i + 1 << " ";
    }
}

void findMissing2(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
            swap(arr[i], arr[index]);
        else
            ++i;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1)
            cout << i + 1 << " ";
    }
}

int main()
{
    vector<int> arr{1, 5, 4, 4, 4};
    findMissing2(arr);
    return 0;
}