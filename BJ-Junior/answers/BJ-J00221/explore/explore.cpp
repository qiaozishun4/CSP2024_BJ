# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 7;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];

// 东南西北
int dix[10] = {0, 1, 0, -1};
int diy[10] = {1, 0, -1, 0};

int n, m, k;
int x, y, d;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        int x0 = x;
        int y0 = y;
        vis[x0][y0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        int cnt = 1;
        int i = 0;
        while (k--)
        {
            i ++;
            int nx = x + dix[d];
            int ny = y + diy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
            {
                if (vis[nx][ny] == false)
                {
                    cnt ++;
                    vis[nx][ny] = true;
                }
                x = nx;
                y = ny;
            }
            else
            {
                int nd = (d+1) % 4;
                d = nd;
            }
//            cout << "i:" << i << " x,y:" << x << "," << y << "  d:" << d << "  cnt:" << cnt << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}
