#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> arr)
{
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
        ans = ans ^ arr[i];

    return ans;
}

int main()
{
    /*
    // create vector
    vector<int> arr;

    int ans = (sizeof(arr) / sizeof(int));
    cout << ans << endl;

    cout << arr.size() << endl;
    cout << arr.capacity() << endl;

    // insert
    arr.push_back(5);
    arr.push_back(6);
    for (int a : arr)
    {
        cout << a << " ";
    }

    int n;
    cout << endl
         << "Enter the value of n => " << endl;

    cin >> n;

    vector<int> brr(n, 101);
    cout << "Size of brr is => " << brr.size() << endl;
    cout << "Capacity of brr is => " << brr.capacity() << endl;

    for (int b : brr)
    {
        cout << b << " ";
    }

    vector<int> crr{10, 20, 30, 40, 50};
    for (int c : crr)
        cout << c << " ";


    // UNIQUE ELEMENT
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    cout << findUnique(arr);

    // union
    int arr[] = {1, 3, 5, 7, 9};
    int sizea = 5;
    int brr[] = {2, 4, 6, 8};
    int sizeb = 4;
    vector<int> ans;

    // push all elements of vector arr
    for (int i = 0; i < sizea; i++)
        ans.push_back(arr[i]);

    // push all elements of vector brr
    for (int i = 0; i < sizeb; i++)
        ans.push_back(brr[i]);

    // printing ans
    cout << "Printing ans array => " << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

        */

    // INTERSECTION

    vector<int> arr{1, 2, 3, 4, 6, 8};
    vector<int> brr{3, 4, 49, 10};

    vector<int> ans;

    // outer loop on arr vector
    for (int i = 0; i < arr.size(); i++)
    {
        int element = arr[i];
        // for every element, run loop on brr
        for (int j = 0; j < brr.size(); j++)
            if (element == brr[j])
            {
                brr[j] = -1;
                ans.push_back(element);
            }
    }

    for (auto value : ans)
        cout << value << " ";

    return 0;
}