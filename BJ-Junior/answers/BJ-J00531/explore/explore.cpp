#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, k;
int x, y, d;
string s[1005];
bool a[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        x -= 1;
        y -= 1;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = false;
            }
        }
        int x1, y1;
        for (int i = 1; i <= k; i++)
        {
            bool flag = true;
            if (d == 0)
            {
                x1 = x;
                y1 = y + 1;
            }
            else if (d == 1)
            {
                x1 = x + 1;
                y1 = y;
            }
            else if (d == 2)
            {
                x1 = x;
                y1 = y - 1;
            }
            else
            {
                x1 = x - 1;
                y1 = y;
            }
            if (x1 >= n || y1 >= m || x1 < 0 || y1 < 0)
            {
                flag = false;
            }
            else if (s[x1][y1] == 'x')
            {
                flag = false;
            }
            if (a[x1][y1] == false && flag)
            {
                ans++;
                x = x1;
                y = y1;
                a[x][y] = true;
                a[x][y] = true;
            }
            else if (flag)
            {
                x = x1;
                y = y1;
            }
            else if (flag == false)
            {
                d++;
                d %= 4;
            }
        }
        cout << ans;
    }
    return 0;
}
