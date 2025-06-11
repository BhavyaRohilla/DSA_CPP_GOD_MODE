#include <iostream>
using namespace std;

class Array
{
public:
    int *A;     // Pointer to the array
    int size;   // Total size
    int length; // Number of elements inserted

    // Constructor: allocate memory for array
    Array(int s)
    {
        size = s;
        A = new int[size];
        length = 0;
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

    // Method to input array elements
    void input()
    {
        cout << "Enter number of elements => ";
        cin >> length;

        if (length > size)
        {
            cout << "Length exceeds size! Limiting to size. \n";
            length = size;
        }

        cout << "Enter " << length << " elements: \n";
        for (int i = 0; i < length; i++)
        {
            cin >> A[i];
        }
    }

    void display()
    {
        cout << "Array Elements : ";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    ~Array()
    {
        delete[] A;
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
    return 0;
}