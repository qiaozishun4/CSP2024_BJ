#include<iostream>
#include<cstring>
using namespace std;

int t;
bool vis[1005][1005];
char mp[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> t;
    while(t --)
    {
        memset(vis, false, sizeof vis);

        int n, m, k, x, y, d, ans = 1;
        cin >> n >> m >> k >> x >> y >> d;
        vis[x][y] = true;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                cin >> mp[i][j];
            }
        }
        for(int i = 1; i <= k; i ++)
        {
            if(d == 0)
            {
                if(mp[x][y + 1] == '.' && y + 1 <= m)
                {
                    y ++;
                    if(!vis[x][y])
                    {
                        vis[x][y] = true;
                        ans ++;
                    }
                }
                else
                {
                    d ++;
                    d %= 4;
                }
            }
            else if(d == 1)
            {
                if(mp[x + 1][y] == '.' && x + 1 <= n)
                {
                    x ++;
                    if(!vis[x][y])
                    {
                        vis[x][y] = true;
                        ans ++;
                    }
                }
                else
                {
                    d ++;
                    d %= 4;
                }
            }
            else if(d == 2)
            {
                if(mp[x][y - 1] == '.' && y - 1 >= 1)
                {
                    y --;
                    if(!vis[x][y])
                    {
                        vis[x][y] = true;
                        ans ++;
                    }
                }
                else
                {
                    d ++;
                    d %= 4;
                }
            }
            else if(d == 3)
            {
                if(mp[x - 1][y] == '.' && x - 1 >= 1)
                {
                    x --;
                    if(!vis[x][y])
                    {
                        vis[x][y] = true;
                        ans ++;
                    }
                }
                else
                {
                    d ++;
                    d %= 4;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}