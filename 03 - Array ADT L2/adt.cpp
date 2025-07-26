#include <iostream>
#include <initializer_list>
using namespace std;

class Array
{
private:
    int *arr;
    int size;
    int length;

    // ✅ Binary Search (Recursive)
    int binarySearchRecursiveHelper(int low, int high, int key)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binarySearchRecursiveHelper(low, mid - 1, key);
        else
            return binarySearchRecursiveHelper(mid + 1, high, key);
    }

public:
    // ✅ 1. Default Constructor (takes input from user)
    Array()
    {
        cout << "Enter total size of array: ";
        cin >> size;
        arr = new int[size];

        cout << "Enter number of elements you want to insert (length ≤ size): ";
        cin >> length;

        if (length > size)
        {
            cout << "Length can't be greater than size! Setting length = size.\n";
            length = size;
        }

        cout << "Enter " << length << " elements:\n";
        for (int i = 0; i < length; i++)
        {
            cout << "Element " << i << ": ";
            cin >> arr[i];
        }
    }

    // Constructor using initializer_list
    Array(std::initializer_list<int> list, int s, int l)
    {
        size = s;
        length = l;
        if (length > size)
        {
            cout << "Length > size! Adjusting to size.\n";
            length = size;
        }

        arr = new int[size];
        int i = 0;
        for (int val : list)
        {
            if (i >= length)
                break;
            arr[i++] = val;
        }
    }

    // ✅ 2. Parameterized Constructor (direct array input)
    Array(int inputArr[], int s, int l)
    {
        size = s;
        length = l;

        if (length > size)
        {
            cout << "Length > size! Adjusting length to size.\n";
            length = size;
        }

        arr = new int[size];
        for (int i = 0; i < length; i++)
        {
            arr[i] = inputArr[i];
        }
    }

    // Destructor
    ~Array()
    {
        delete[] arr;
    }

    // Display Array
    void display()
    {
        cout << "Array: ";
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Add / Append
    void append(int value)
    {
        if (length < size)
            arr[length++] = value;
        else
            cout << "❌ Array is full. Cannot append more elements.\n";
    }

    // Insert
    void insert(int index, int value)
    {
        if (index >= 0 && index <= length && length < size)
        {
            for (int i = length; i > index; i--)
            {
                arr[i] = arr[i - 1]; // right shift
            }
            arr[index] = value;
            length++;
        }
        else
            cout << "❌ Invalid index or array is full.\n";
    }

    // Delete
    void remove(int index)
    {
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length - 1; i++)
                arr[i] = arr[i + 1];
            length--;
        }
        else
            cout << "❌ Invalid index. Cannot remove.\n";
    }

    // Searching
    // ✅ Basic Linear Search
    int linearSearch(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    // ✅ Linear Search with Transposition (swap with previous element)
    int linearSearchTransposition(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
            {
                if (i > 0)
                    swap(arr[i], arr[i - 1]); // Move closer to front
                return i;
            }
        }
        return -1;
    }

    // ✅ Linear Search with Move to Front (Head)
    int linearSearchMoveToFront(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
            {
                swap(arr[i], arr[0]); // Bring to front
                return 0;
            }
        }
        return -1;
    }

    // ✅ Binary Search (Iterative)
    int binarySearch(int key)
    {
        int low = 0;
        int high = length - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
                return mid;
            else if (key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    // Recursive Binary Search
    int binarySearchRecursive(int key)
    {
        return binarySearchRecursiveHelper(0, length - 1, key);
    }

    // ✅ Get element at index
    int get(int index)
    {
        if (index >= 0 && index < length)
            return arr[index];
        cout << "Invalid index\n";
        return -1;
    }

    // ✅ Set element at index
    void set(int index, int value)
    {
        if (index >= 0 && index < length)
            arr[index] = value;
        else
            cout << "Invalid index\n";
    }

    // ✅ Iterative sum
    int sum()
    {
        int total = 0;
        for (int i = 0; i < length; i++)
            total += arr[i];
        return total;
    }

    // ✅ Recursive sum
    int recursiveSumHelper(int n)
    {
        if (n < 0)
            return 0;
        return recursiveSumHelper(n - 1) + arr[n];
    }

    int recursiveSum()
    {
        return recursiveSumHelper(length - 1);
    }

    // ✅ Minimum element
    int min()
    {
        if (length == 0)
            return -1;
        int minVal = arr[0];
        for (int i = 1; i < length; i++)
            if (arr[i] < minVal)
                minVal = arr[i];
        return minVal;
    }

    // ✅ Maximum element
    int max()
    {
        if (length == 0)
            return -1;
        int maxVal = arr[0];
        for (int i = 1; i < length; i++)
            if (arr[i] > maxVal)
                maxVal = arr[i];
        return maxVal;
    }

    // ✅ Reverse the array (in-place)
    void reverse()
    {
        int start = 0, end = length - 1;
        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    // ✅ Left shift by 1 position (fills last with 0)
    void leftShift()
    {
        if (length == 0)
            return;
        for (int i = 0; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = 0;
    }

    // ✅ Right shift by 1 position (fills first with 0)
    void rightShift()
    {
        if (length == 0)
            return;
        for (int i = length - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = 0;
    }

    // ✅ Left rotate by 1 (first element goes to last)
    void leftRotate()
    {
        if (length == 0)
            return;
        int first = arr[0];
        for (int i = 0; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = first;
    }

    // ✅ Right rotate by 1 (last element goes to first)
    void rightRotate()
    {
        if (length == 0)
            return;
        int last = arr[length - 1];
        for (int i = length - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }

    // ✅ Check if array is sorted (non-decreasing)
    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    // ✅ Insert in a sorted array (maintains sorted order)
    void insertSorted(int x)
    {
        if (length == size)
        {
            cout << "Array Full! \n";
            return;
        }
        int i = length - 1;
        while (i >= 0 && arr[i] > x)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = x;
        length++;
    }

    // ✅ Rearrange: move all negative numbers to left, positives to right (Stable Partition)
    void rearrangeNegativePositive()
    {
        int i = 0, j = 0;
        while (i < length)
        {
            if (arr[i] < 0)
            {
                if (i != j)
                    swap(arr[i], arr[j]);
                j++;
            }
            i++;
        }
    }

    // Merge arrays
    // Array merge(const Array &arr2)
    // {
    //     Array result(size + arr2.size); // final size = dono ka combined
    //     result.length = length + arr2.length;

    //     int i = 0, j = 0, k = 0;

    //     // Assuming both arrays are sorted
    //     while (i < length && j < arr2.length)
    //     {
    //         if (arr[i] < arr2.arr[j])
    //             result.arr[k++] = arr[i++];
    //         else
    //             result.arr[k++] = arr2.arr[j++];
    //     }

    //     while (i < length)
    //         result.arr[k++] = arr[i++];

    //     while (j < arr2.length)
    //         result.arr[k++] = arr2.arr[j++];

    //     return result;
    // }
};

int main()
{
    int data[] = {1, 2, 3, 4, 5};
    Array a1(data, 10, 5);
    a1.append(20);
    a1.insert(2, 500);
    a1.remove(0);
    a1.display();
    cout << a1.get(2) << endl;
    a1.set(1, 1000);
    a1.display();
    // cout << a1.binarySearchRecursive(500);

    return 0;
}