#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        bool Map[MAXN][MAXN] = {};
        bool Vis[MAXN][MAXN] = {};
        memset(Vis, true, sizeof(Vis));
        int n, m, k;
        int x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        char c;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin >> c;
                if(c == '.') Map[i][j] = true;
                else Map[i][j] = false;
            }
        int cnt=1;
        for(int i=1; i<=k; i++)
            if(d == 0)
                if(Map[x][y+1] && x > 0 && x <= n && y > 0 && y <= m)
                {
                    y++;
                    if(Vis[x][y])
                        cnt++, Vis[x][y] = false;
                }
                else d++;
            else if(d == 1)
                if(Map[x+1][y] && x > 0 && x <= n && y > 0 && y <= m)
                {
                    x++;
                    if(Vis[x][y])
                        cnt++, Vis[x][y] = false;
                }
                else d++;
            else if(d == 2)
                if(Map[x][y-1] && x > 0 && x <= n && y > 0 && y <= m)
                {
                    y--;
                    if(Vis[x][y])
                        cnt++, Vis[x][y] = false;
                }
                else d++;
            else
                if(Map[x-1][y] && x > 0 && x <= n && y > 0 && y <= m)
                {
                    x--;
                    if(Vis[x][y])
                        cnt++, Vis[x][y] = false;
                }
                else d=0;
        cout << cnt << endl;
    }
    return 0;
}
