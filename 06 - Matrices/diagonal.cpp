#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int arr[10][10]; // assuming max size 10x10
    int n;

public:
    void input()
    {
        cout << "Enter size of square matrix: ";
        cin >> n;

        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    bool isDiagonal()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && arr[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void display()
    {
        cout << "Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    DiagonalMatrix matrix;

    matrix.input();
    matrix.display();

    if (matrix.isDiagonal())
    {
        cout << "Matrix is a Diagonal Matrix." << endl;
    }
    else
    {
        cout << "Matrix is NOT a Diagonal Matrix." << endl;
    }

    return 0;
}
