#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
bool w[1005][1005], mp[1005][1005];
char s[1005];
const int dx[] = {0, 1, 0, -1},
dy[] = {1, 0, -1, 0};
signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%lld", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        int x, y, d;
        scanf("%lld %lld %lld", &x, &y, &d);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; j++)
            {
                w[i][j] = 0;
                if (s[j] == 'x')
                    w[i][j] = 1;
                mp[i][j] = 0;
            }
        }
        mp[x][y] = 1;
        for (int i = 1; i <= k; i++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !w[nx][ny])
            {
                x = nx, y = ny;
            }
            else
            {
                d = (d + 1) % 4;
            }
            mp[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (mp[i][j])
                    cnt++;
        printf("%lld\n", cnt);
    }
    return 0;
}