#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
const int dx[] = {0, 1,  0, -1};
const int dy[] = {1, 0, -1,  0};
bool vis[1010][1010];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int TT;
    cin >> TT;
    while(TT--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        for(int i = 1; i <= k; i++)
        {
            vis[x][y] = 1;
            int tx = x + dx[d], ty = y + dy[d];
            if(a[tx][ty] == '.')
            {
                x = tx;
                y = ty;
            }
            else d = (d + 1) % 4;
        }
        vis[x][y] = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cnt += vis[i][j];
        cout << cnt << "\n";
    }
    return 0;
}
