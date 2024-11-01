#include <bits/stdc++.h>
using namespace std;
int T,n,m,t,d,ans,nx,ny;
char p[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> t >> nx >> ny >> d;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                cin >> p[i][j];
            }
        }
        ans = 1;
        for (int i = 1;i <= t;i++)
        {
            if (d == 0)
            {
                if (p[nx][ny+1] == '.')
                {
                    p[nx][ny] = 'x';
                    ny++;
                    ans++;
                    continue;
                }
            }
            else if (d == 1)
            {
                if (p[nx+1][ny] == '.')
                {
                    p[nx][ny] = 'x';
                    nx++;
                    ans++;
                    continue;
                }
            }
            else if (d == 2)
            {
                if (p[nx][ny-1] == '.')
                {
                    p[nx][ny] = 'x';
                    ny--;
                    ans++;
                    continue;
                }
            }
            else
            {
                if (p[nx-1][ny] == '.')
                {
                    p[nx][ny] = 'x';
                    nx--;
                    ans++;
                    continue;
                }
            }
            d = (d + 1) % 4;
        }
        cout << ans;
    }
    return 0;
}
