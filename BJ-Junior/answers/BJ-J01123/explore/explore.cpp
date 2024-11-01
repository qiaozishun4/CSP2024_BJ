#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
struct Mp{
    char op;
    bool beUsed;
} mp[N][N];
int t, n, m, k;
int x, y ,d;
int nextX[] = {0, 1, 0, -1};
int nextY[] = {1, 0, -1, 0};
void solve()
{
    int ans = 1;
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j].op;
            mp[i][j].beUsed = 0;
        }
    }
    mp[x][y].beUsed = 1;
    for (int i = 1; i <= k; i++)
    {
        int tmpx = x + nextX[d];
        int tmpy = y + nextY[d];
        if (tmpx <= n && tmpy <= m && tmpx != 0 && tmpy != 0 && mp[tmpx][tmpy].op != 'x')
        {
            x += nextX[d];
            y += nextY[d];
            if (mp[x][y].beUsed == 0) ans++;
            mp[x][y].beUsed = 1;
        } else {
            d = (d + 1) % 4;
        }
    }
    cout << ans << endl;

}

signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
