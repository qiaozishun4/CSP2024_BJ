#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "W", stdout);
    int d = 0, q = 0;
    int T, n, m, k, d;
    char a[1000010];
    cin >> T >> n >> m >> k >> d >> a[1000010];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(k == q)
            {
                cout << q;
            }
            if(a[i][j+1] == "." && d == 0)
            {
                a[i][j] = a[i][j+1];
                q++;
            }
            else if(a[i+1][j] == "." && d == 1);
            {
                a[i][j] =  a[i+1][j];
                q++;
            }
            else if(a[i][j-1] = "." && d == 2)
            {
                a[i][j] = a[i][j-1];
                q++;
            }
            else if(a[i-1][j] = "." && d = 3)
            {
                a[i][j] = a[i-1][j];
                q++;
            }
            else
            {
                d++;
                q++;
            }
        }
    }
    return 0;
}