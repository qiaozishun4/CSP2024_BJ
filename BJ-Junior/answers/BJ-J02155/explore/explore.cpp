#include <bits/stdc++.h>
using namespace std;

int T, n, m, k, xx, yy, d;
char g[1010][1010];
bool vis[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--)
    {
        memset(vis, false , sizeof(vis));
        cin >> n >>m >>k;
        cin >> xx >> yy >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >>g[i][j];
            }
        }
        vis[xx][yy] = true;
        for(int i = 1; i <= k;i ++)
        {
            xx += dx[d];
            yy += dy[d];
            if(1 <= xx && xx <= n && 1 <= yy && yy <= m && g[xx][yy] == '.')
            {
                vis[xx][yy] = true;
            }
            else
            {
                xx -= dx[d];
                yy -= dy[d];
                d++;
                d %= 4;
            }
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                ans += vis[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
