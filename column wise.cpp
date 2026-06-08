#include <iostream>
#include <algorithm>
using namespace std;

const int p = 100;

int flll(int arr[][p], int c, int m)
{
    int mx = arr[0][c];

    for(int i = 1; i < m; i++)
    {
        mx = max(mx, arr[i][c]);
    }

    return mx;
}

int slll(int arr[][p], int c, int m)
{
    int f = arr[0][c];
    int s = -1;

    for(int i = 1; i < m; i++)
    {
        if(arr[i][c] > f)
        {
            s = f;
            f = arr[i][c];
        }
        else if(arr[i][c] > s)
        {
            s = arr[i][c];
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

            if(j == 0)
            {
                b[i][0] = a[i][j];
            }
        }
    }

    for(int j = 1; j < n; j++)
    {
        int fl = flll(b, j - 1, m);
        int sl = slll(b, j - 1, m);

        for(int i = 0; i < m; i++)
        {
            if(b[i][j - 1] == fl)
            {
                b[i][j] = a[i][j] + sl;
            }
            else
            {
                b[i][j] = a[i][j] + fl;
            }
        }
    }

    int ans = b[0][n - 1];

    for(int i = 1; i < m; i++)
    {
        ans = max(ans, b[i][n - 1]);
    }

    cout << ans;

    return 0;
}
