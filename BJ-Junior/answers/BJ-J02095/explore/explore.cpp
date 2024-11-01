#include<bits/stdc++.h>
using namespace std;

int T;
char a[10005][10005];
int yx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};
int vis[10005][10005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        int n, m, k;
        int x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        int cnt = 1;
        vis[x][y] = 1;
        for(int i = 1; i <= k; i++)
        {
            if(x + yx[d] < 1 || x + yx[d] > n || y + yy[d] < 1 || y + yy[d] > m || a[x + yx[d]][y + yy[d]] == 'x')
            {
                d = (d + 1) % 4;
            }
            else
            {
                x += yx[d];
                y += yy[d];
                if(vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
