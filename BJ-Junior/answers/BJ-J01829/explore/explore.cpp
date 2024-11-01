#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005], mp[1005][1005];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k;
int st_x, st_y, st_dir;
void solve()
{
    memset(vis, 0, sizeof vis);
    memset(mp, 0, sizeof mp);
    cin >> n >> m >> k;
    cin >> st_x >> st_y >> st_dir;
    for(int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++) mp[i][j+1] = (tmp[j] == '.');
    }
    int ans = 1;
    vis[st_x][st_y] = true;
    while(k--)
    {
        int tmp_x = st_x + dir[st_dir][0], tmp_y = st_y + dir[st_dir][1];
        if(tmp_x <= 0 || tmp_y <= 0 || tmp_x > n || tmp_y > m || mp[tmp_x][tmp_y] == false) st_dir = (st_dir + 1) % 4;
        else st_x = tmp_x, st_y = tmp_y;
        if(vis[st_x][st_y] == false)
        {
            ans++;
            vis[st_x][st_y] = true;
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}
