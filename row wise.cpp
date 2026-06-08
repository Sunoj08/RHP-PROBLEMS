#include <iostream>
#include <algorithm>
using namespace std;

const int p = 100;

int flll(int arr[][p], int r, int n)
{
    return *max_element(arr[r], arr[r] + n);
}

int slll(int arr[][p], int r, int n)
{
    int f = arr[r][0];
    int s = -1;

    for(int i = 1; i < n; i++)
    {
        if(arr[r][i] > f)
        {
            s = f;
            f = arr[r][i];
        }
        else if(arr[r][i] > s)
        {
            s = arr[r][i];
        }
    }

    return s;
}

int main()
{
    int m, n;
    cin >> m >> n;

    int a[100][p], b[100][p];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // First row of DP
    for(int j = 0; j < n; j++)
    {
        b[0][j] = a[0][j];
    }

    for(int i = 1; i < m; i++)
    {
        int fl = flll(b, i - 1, n); 
        int sl = slll(b, i - 1, n); 

        for(int j = 0; j < n; j++)
        {
            if(b[i - 1][j] == fl)
            {
                b[i][j] = a[i][j] + sl;
            }
            else
            {
                b[i][j] = a[i][j] + fl;
            }
        }
    }

    cout << *max_element(b[m - 1], b[m - 1] + n);

    return 0;
}
