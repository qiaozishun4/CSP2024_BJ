#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char a[1010][1010];
bool vis[1010][1010];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        memset(a, 0, sizeof(a));
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = s[j - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            a[i][0] = 'x';
            a[i][m + 1] = 'x';
        }
        for (int i = 1; i <= m; i++)
        {
            a[0][i] = 'x';
            a[n + 1][i] = 'x';
        }
        vis[x][y] = true;
        while (k--)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (a[nx][ny] == 'x')
            {
                d++;
                d %= 4;
            }
            else
            {
                x = nx;
                y = ny;
                vis[x][y] = true;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ans += vis[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
