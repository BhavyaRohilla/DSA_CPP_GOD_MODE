#include <iostream>
using namespace std;

void printRowWiseSum(int arr[][3], int rows, int column)
{
    // row sum -> row-wise traversal
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < column; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}

void printColumnWiseSum(int arr[][3], int rows, int column)
{
    // column sum -> column-wise traversal
    for (int i = 0; i < column; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += arr[j][i];
        }
        cout << "Column => " << sum << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printRowWiseSum(arr, 3, 3);
    printColumnWiseSum(arr, 3, 3);
    return 0;
}