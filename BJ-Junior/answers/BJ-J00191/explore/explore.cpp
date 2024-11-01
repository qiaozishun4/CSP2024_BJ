#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e+4+15;
int inf = 0x7FFFFFFF;
int t;
int n, m, k, fx, fy, fd, cnt = 0;
const int dx[] = {0, 1,  0, -1};
const int dy[] = {1, 0, -1,  0};
char a[N][N];
bool visi[N][N];
bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int dfs(int x, int y, int d)
{
    if ( k > 0 )
    {
        for (int i = d; i <= d + 4; i++)
        {
            int nd = i % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            k--;
            if ( !check(nx, ny) || a[nx][ny] == 'x' ) continue;
            if ( !visi[nx][ny] )
            {
                visi[nx][ny] = true;
                cnt++;
                return dfs(nx, ny, nd);
            }
            else
            {
                return dfs(nx, ny, nd);
            }
        }
    }
    return cnt;
}
int main (  )
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    cin >> t;
    while ( t-- )
    {
        cnt = 0;
        memset(visi, 0, sizeof(visi));
        cin >> n >> m >> k;
        cin >> fx >> fy >> fd;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << dfs(fx, fy, fd) << endl;
    }
    return 0;
}


