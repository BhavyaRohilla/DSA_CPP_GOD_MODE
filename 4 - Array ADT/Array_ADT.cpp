#include <iostream>
#include <climits>
using namespace std;

class Array
{
public:
    int *A;     // Pointer to the array
    int size;   // Total size
    int length; // Number of elements inserted

    // Constructor: allocate memory for array
    Array(int s) : size(s), length(0)
    {
        A = new int[size];
    }

    // Append function to add value at end
    void append(int value)
    {
        if (length < size)
        {
            A[length++] = value;
        }
        else
            cout << "Array is full. Cannot append. \n";
    }

    // Insert value at index
    void insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            cout << "Invalid index. \n";
            return;
        }
        if (length >= size)
        {
            cout << "Array is full. Cannot insert. \n";
            return;
        }

        // Shift element right
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = value;
        length++;
    }

    // Delete element at index
    void deleteElement(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Invalid index. \n";
            return;
        }
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }

    // Swap two elements by reference
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    int linearSearchTransposition(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == key)
            {
                if (i > 0)
                {
                    swap(&A[i], &A[i - 1]);
                    return i - 1;
                }
                return i;
            }
        }
        return -1;
    }

    // Optimised Binary Search
    int binarySearch(int key)
    {
        int low = 0, high = length - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (A[mid] == key)
                return mid;
            else if (A[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // Recursive binary approach
    int recursiveBinarySearch(int low, int high, int key)
    {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            return recursiveBinarySearch(mid + 1, high, key);
        else
            return recursiveBinarySearch(low, mid - 1, key);
    }

    // Getting a value
    int get(int index)
    {
        if (index >= 0 && index < length)
            return A[index];
        else
        {
            cout << "Index out of bounds!\n";
            return -1; // or some sentinel value
        }
    }

    // Setting a value
    void set(int index, int value)
    {
        if (index >= 0 && index < length)
            A[index] = value;
        else
            cout << "Index out of bounds! \n";
    }

    // Method to input array elements
    void input()
    {
        int len;
        cout << "Enter number of elements => ";
        cin >> len;

        if (len > size)
        {
            cout << "Length exceeds size! Limiting to size. \n";
            len = size;
        }

        cout << "Enter " << len << " elements: \n";
        for (int i = 0; i < len; i++)
        {
            cin >> A[i];
        }
        length = len; // ✅ Only update length after successful input
    }

    // find max value in array
    int max()
    {
        if (length == 0)
        {
            cout << "Array is empty.\n";
            return INT_MIN;
        }
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }

    // find min value in array
    int min()
    {
        if (length == 0)
        {
            cout << "Array is empty.\n";
            return INT_MAX;
        }
        int min = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] < min)
                min = A[i];
        }
        return min;
    }

    // Sum of array
    int sum()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum;
    }

    // Finding average
    float average()
    {
        return (length == 0) ? 0 : (float)sum() / length;
    }

    // For reverse
    void reverse()
    {
        int *arr = new int[length];
        for (int i = length - 1, j = 0; i >= 0; i--, j++)
            arr[j] = A[i];
        for (int i = 0; i < length; i++)
        {
            A[i] = arr[i];
        }
    }

    // reverse 2
    void reverse2()
    {
        for (int i = 0, j = length - 1; i < j; i++, j--)
            swap(&A[i], &A[j]);
    }

    // Display array
    void display()
    {
        cout << "Array Elements : ";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // Insert sort
    void insertSort(int x)
    {
        int i = length - 1;
        if (length == size)
            return;
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }

    // Check the array is sorted or not
    bool isSorted() const
    {
        for (int i = 0; i < length - 1; i++)
            if (A[i] > A[i + 1])
                return false;

        return true;
    }

    // Merge two arrays
    Array *merge(int arr2[], int len2)
    {
        Array *result = new Array(length + len2);
        int i = 0, j = 0, k = 0;

        while (i < length && j < len2)
        {
            if (A[i] < arr2[j])
                result->A[k++] = A[i++];
            else
                result->A[k++] = arr2[j++];
        }

        while (i < length)
            result->A[k++] = A[i++];
        while (j < len2)
            result->A[k++] = arr2[j++];

        result->length = k;
        return result;
    }

    // Get the length of the array
    int getLength() const { return length; }

    void rearrangePositiveNegative()
    {
        int i = 0;
        int j = length - 1;

        while (i < j)
        {
            // Move forward if A[i] is negative
            while (A[i] < 0 && i < j)
                i++;
            // Move j backward if A[j] is positive
            while (A[j] >= 0 && i < j)
                j--;

            if (i < j)
                swap(&A[i], &A[j]);
        }
    }

    ~Array()
    {
        delete[] A;
        A = nullptr;
    }
};

int main()
{
    int n, index, value;
    cout << "Enter the size of Array : ";
    cin >> n;
    Array arr(n);  // Create array object of size n
    arr.input();   // Take input
    arr.display(); // Show contents

    // Test append
    /*
    int val;
    cout << "Enter the value to append => ";
    cin >> val;
    arr.append(val);

    cout << "After append : \n";
    arr.display();
    */

    // Insertion
    /*

    cout << "Enter index and value to insert: ";
    cin >> index >> value;

    arr.insert(index, value);
    cout << "After insertion: \n";
    arr.display();
    */

    // Deletion
    /*
    cout << "Enter index to delete => ";
    cin >> index;
    arr.deleteElement(index);
    cout << "After Deletion : \n";
    arr.display();
    */

    // linear search
    /*
    int key;
    cout << "Enter key to search (with transposition) : ";
    cin >> key;

    index = arr.linearSearchTransposition(key);

    if (index != -1)
    {
        cout << "Key found at index (after transposition): " << index << endl;
    }
    else
    {
        cout << "Key not found.\n";
    }

    cout << "Array after transposition: \n";
    arr.display();
    */

    // 🔍 Binary Search
    /*
    int key;
    cout << "Enter key to binary search: ";
    cin >> key;
    int result = arr.binarySearch(key);

    if (result != -1)
        cout << "Key found at index: " << result << endl;
    else
        cout << "Key not found.\n";
        */

    // Recursive Binary Search
    /*
    int key;
    cout << "Enter key for recursive binary search: ";
    cin >> key;
    int recurResult = arr.recursiveBinarySearch(0, arr.getLength() - 1, key);

    if (recurResult != -1)
        cout << "Recursive Binary Search: Found at index " << recurResult << endl;
    else
        cout << "Recursive Binary Search: Not found\n";
    */

    // getting the value
    /*
    cout << "Enter index to get the value => ";
    cin >> index;
    int val = arr.get(index);
    cout << "Value at index " << index << " is => " << val << endl;
    */

    // setting a value
    /*
    cout << "Enter index and new value to set => ";
    cin >> index >> value;

    arr.set(index, value);
    cout << "After setting, array becomes => \n";
    arr.display();
    */

    // cout << arr.max() << endl;
    // cout << arr.min() << endl;
    // cout << arr.sum() << endl;
    // cout << arr.average() << endl;

    // arr.reverse2();
    // arr.display();
    // arr.insertSort(12);
    // arr.display();

    // if (arr.isSorted())
    // {
    //     cout << "Array is sorted";
    // }
    // else
    // {
    //     cout << "Not sorted";
    // }

    // arr.rearrangePositiveNegative();
    // arr.display();

    int arr2[] = {2, 5, 6, 7, 8, 9};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    Array *merged = arr.merge(arr2, len2);
    merged->display();

    delete merged;

    return 0;
}