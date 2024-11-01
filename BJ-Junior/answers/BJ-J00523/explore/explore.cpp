#include<bits/stdc++.h>
using namespace std;

char s[1001][1001];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T, n, m, k, d, x, y,cnt = 1;
    cin >> T;
    for(int i = 1;i <= T;i++)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for(int j = 1;j <= n;j++)
        {
            cin >> s[j];
        }
        for(int j = 0;j <= k;j++)
        {
            if(d == 0)
            {
                if(s[x][++y] == '.' && x <= n && y <= m && x >= 1 && y >= 1)
                {
                    cnt++;
                }
                else
                {
                    d = (d + 1) % 4;
                    y--;
                    continue;
                }
            }
            if(d == 1)
            {
                if(s[++x][y] == '.' && x <= n && y <= m && x >= 1 && y >= 1)
                {
                    cnt++;
                }
                else
                {
                    d = (d + 1) % 4;
                    x--;
                    continue;
                }
            }
            if(d == 2)
            {
                if(s[x][--y] == '.' && x <= n && y <= m && x >= 1 && y >= 1)
                {
                    cnt++;
                }
                else
                {
                    d = (d + 1) % 4;
                    y++;
                    continue;
                }
            }
            if(d == 3)
            {
                if(s[--x][y] == '.' && x <= n && y <= m && x >= 1 && y >= 1)
                {
                    cnt++;
                }
                else
                {
                    d = (d + 1) % 4;
                    x++;
                    continue;
                }
            }
        }
        cout << cnt << endl;
        cnt = 1;
    }
    return 0;
}
