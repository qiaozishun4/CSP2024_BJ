#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char c[N][N];
bool vis[N][N];
int n, m;
bool inb(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] != 'x');
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(vis, false, sizeof(vis));
        int k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin >> c[i][j];
        vis[x][y] = true;
        int cnt = 1;
        while(k--)
        {
            int vx, vy;
            vx = x + dx[d], vy = y + dy[d];
            if(inb(vx, vy))
            {
                if(!vis[vx][vy])
                    vis[vx][vy] = true, cnt++;
                x = vx, y = vy;
            }
            else
                d = (d + 1) % 4;
        }
        cout << cnt << '\n';
    }
    return 0;
}