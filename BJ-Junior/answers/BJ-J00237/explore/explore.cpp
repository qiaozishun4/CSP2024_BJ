#include<bits/stdc++.h>
using namespace std;

bool a[1010][1010], b[1010][1010];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, m, k, ans = 1;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        memset(a, false, sizeof(a));
        memset(b, false, sizeof(b));
        b[x][y] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                if (c == '.') a[i][j] = true;
                else if (c == 'x') a[i][j] = false;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (d == 0)
            {
                if (y + 1 > m || a[x][y + 1] == false)
                {
                    d++;
                    d = d % 4;
                }
                else
                {
                    y++;
                    if (b[x][y] == false)
                    {
                        b[x][y] = true;
                        ans++;
                    }
                }
            }
            else if (d == 1)
            {
                if (x + 1 > n || a[x + 1][y] == false)
                {
                    d++;
                    d = d % 4;
                }
                else
                {
                    x++;
                    if (b[x][y] == false)
                    {
                        b[x][y] = true;
                        ans++;
                    }
                }
            }
            else if (d == 2)
            {
                if (y - 1 < 1 || a[x][y - 1] == false)
                {
                    d++;
                    d = d % 4;
                }
                else
                {
                    y--;
                    if (b[x][y] == false)
                    {
                        b[x][y] = true;
                        ans++;
                    }
                }
            }
            else if (d == 3)
            {
                if (x - 1 < 1 || a[x - 1][y] == false)
                {
                    d++;
                    d = d % 4;
                }
                else
                {
                    x--;
                    if (b[x][y] == false)
                    {
                        b[x][y] = true;
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
