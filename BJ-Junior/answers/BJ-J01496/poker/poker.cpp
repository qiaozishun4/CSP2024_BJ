#include <bits/stdc++.h>
using namespace std;

int a[5][15];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c, x;
        cin >> c >> x;
        int y;
        if (x == 'A')
        {
            y = 1;
        }
        else if (x == 'T')
        {
            y = 10;
        }
        else if (x == 'J')
        {
            y = 11;
        }
        else if (x == 'Q')
        {
            y = 12;
        }
        else if (x == 'K')
        {
            y = 13;
        }
        else
        {
            y = x - '0';
        }
        if (c == 'D')
        {
            a[1][y] = 1;
        }
        else if (c == 'C')
        {
            a[2][y] = 1;
        }
        else if (c == 'H')
        {
            a[3][y] = 1;
        }
        else
        {
            a[4][y] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (!a[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
