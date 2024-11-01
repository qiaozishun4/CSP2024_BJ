#include <iostream>
#include <cstring>
#define int long long
using namespace std;
string s;
int T, n, m, k, x, y, d, cnt;
bool mapp[1005][1005], vis[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void nxt()
{
    int xx = x + dx[d];
    int yy = y + dy[d];
    if (mapp[xx][yy])
        x = xx, y = yy;
    else
        d = (d + 1) % 4;
}
signed main()
{
    // if k <= 10^9?
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        memset(vis, 0, sizeof(vis));
        memset(mapp, 0, sizeof(mapp)); // x around map
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                if (s[j - 1] == '.')
                    mapp[i][j] = true;
            }
        }
        vis[x][y] = true;
        for (int p = 1; p <= k; p++)
        {
            nxt();
            vis[x][y] = true;
        }
        cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j])
                    cnt++;
        cout << cnt << endl;
    }
    return 0;
}
