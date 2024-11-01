#include <bits/stdc++.h>
using namespace std;
#define int long long
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int N = 1e3 + 10;

int T, n, m, k, x00, y00, d00, ans;
bool can[N][N], vis[N][N];

void insert()
{
    cin >> n >> m >> k >> x00 >> y00 >> d00;
    char c;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            can[i][j] = (c == '.');
        }
}

void work()
{
    insert();
    memset(vis, 0, sizeof vis);
    ans = 1;
    vis[x00][y00] = 1;
    int x = x00, y = y00, d = d00, nx, ny;
    while(k--)
    {
        nx = x + dx[d], ny = y + dy[d];
        if(1 <= nx && nx <= n && 1 <= ny && ny <= m && can[nx][ny])
            x = nx, y = ny;
        else
            d = (d + 1) % 4;
        if(!vis[x][y])
            ans++, vis[x][y] = 1;
    }
    cout << ans << endl;
}

signed main()
{
    freopen("explore.out", "w", stdout);
    freopen("explore.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> T;
    while(T--)
        work();
}