#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
char c[1005][1005];
int f[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                cin >> c[i][j];
                f[i][j] = 0;
            }
        }
        f[x][y] = 1;
        while (k--)
        {
            int xx = x + dx[d],yy = y + dy[d];
            if (xx < 1 || xx > n || yy < 1 || yy > m || c[xx][yy] == 'x') d = (d + 1) % 4;
            else
            {
                x = xx;
                y = yy;
                f[x][y] = 1;
            }
        }
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                ans += f[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}