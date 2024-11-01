#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
char a[1005][1005];
bool f[1005][1005];
int ad[4][2]= {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(f, false, sizeof(f));
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        f[x][y] = true;
        while(k--)
        {
            int xx = x + ad[d][0];
            int yy = y + ad[d][1];
            if(xx == 0 || yy == 0 || xx == n + 1 || yy == m + 1 || a[xx][yy] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            f[xx][yy] = true;
            x = xx;
            y = yy;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                ans += f[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
