#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int N = 1e3 + 5;
char mp[N][N];
bool vis[N][N];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, f;
        cin >> x >> y >> f;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                cin >> mp[i][j];
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                vis[i][j] = 0;
        int cnt = 1;
        vis[x][y] = 1;
        while (k --)
        {
            int nx = x + dx[f];
            int ny = y + dy[f];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.')
            {
                x = nx, y = ny;
                if (!vis[x][y])
                    vis[x][y] = 1, cnt ++;
            }
            else f = (f + 1) % 4;
        }
        cout << cnt << "\n";
    }

    return 0;
}