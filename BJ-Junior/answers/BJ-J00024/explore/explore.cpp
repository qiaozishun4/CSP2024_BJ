#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char a[N][N];
bool vis[N][N];
int n, m;

bool in(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, false, sizeof(vis));
        int k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        vis[x][y] = true;
        int cnt = 0;
        while (cnt < k)
        {
            for (int p = 1; p <= 4; p++)
            {
                cnt++;
                if (cnt > k) break;
                int nx = x + dx[d], ny = y + dy[d];
                //cout << d <<" " << x << " " << y <<" "<< nx << " " << ny << " " << (in(nx, ny) && a[nx][ny] == '.') <<endl;
                if (in(nx, ny) && a[nx][ny] == '.')
                {

                    vis[nx][ny] = true;
                    x = nx, y = ny;
                    break;
                }
                d = (d + 1) % 4;

            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j])
                    ans++;
        cout << ans << endl;
    }


    return 0;
}
