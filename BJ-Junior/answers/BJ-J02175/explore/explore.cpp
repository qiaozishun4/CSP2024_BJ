#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n, m, k;
char mp[1005][1005];
bool vis[1005][1005];
ll p[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair <ll, ll> get_nxt_point(ll x, ll y, ll d)
{
    pair <ll, ll> ans;
    ans.first = x + p[d][0];
    ans.second = y + p[d][1];
    return ans;
}
ll get_nxt_d(ll d)
{
    return (d + 1) % 4;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        ll x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        vis[x][y] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> mp[i][j];
        while(k--)
        {
            pair <ll, ll> new_point = get_nxt_point(x, y, d);
            ll nx = new_point.first, ny = new_point.second;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.')
            {
                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
            else
                d = get_nxt_d(d);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                ans += vis[i][j];
                vis[i][j] = 0;
            }
        cout << ans << "\n";
    }
    return 0;
}