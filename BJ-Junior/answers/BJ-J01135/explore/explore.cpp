#include <bits/stdc++.h>
using namespace std;
pair<int, int> dir[5] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
string s[1010];
bool flag[1010][1010];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n, m, k, x, y, d;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        int ans = 1;
        flag[x][y] = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> s[i];
            s[i] = "x" + s[i];
        }
        while (k--)
        {
            int tx = x, ty = y;
            tx += dir[d].first, ty += dir[d].second;
            if (tx < 1 || tx > n ||ty < 1 || ty > m || s[tx][ty] != '.')
            {
                d = (d + 5) % 4;
            }
            else
            {
                x = tx;
                y = ty;
                if (!flag[x][y])
                {
                    flag[x][y] = true;
                    ++ans;
                }
            }
        }
        cout << ans << "\n";
        memset(flag, 0, sizeof(flag));
    }
    return 0;
}
