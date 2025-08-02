class LowerTriangular
{
    int *arr;
    int n;

public:
    LowerTriangular(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int val)
    {
        if (i >= j)
            arr[i * (i + 1) / 2 + j] = val;
    }

    int get(int i, int j)
    {
        if (i >= j)
            return arr[i * (i + 1) / 2 + j];
        else
            return 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~LowerTriangular()
    {
        delete[] arr;
    }
};
