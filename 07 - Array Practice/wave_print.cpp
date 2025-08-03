#include <iostream>
#include <vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>> v)
{
    if (v.empty() || v[0].empty())
    {
        cout << "Matrix is empty" << endl;
        return;
    }

    int m = v.size();
    int n = v[0].size();

    for (int i = 0; i < m; i++)
    {
        if (v[i].size() != n)
        {
            cout << "Row size mismatch" << endl;
            return;
        }
    }

    for (int startCol = 0; startCol < n; startCol++)
    {
        if (startCol % 2 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << v[i][startCol] << " ";
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << v[i][startCol] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    wavePrintMatrix(v);
    return 0;
}
