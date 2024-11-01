#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char s[1005][1005],vis[1005][1005];
int check()
{
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (vis[i][j] == '1')
            {
                cnt++;
            }
        }
    }
    return cnt;
}
void walk(int x,int y,int d,int w,int ans)
{
    if (w == k)
    {
        cout << check() << endl;
        exit(0);
    }
    else
    {
        if (d == 0)
        {
            if (y + 1 > m || s[x][y + 1] == 'x')
                walk(x,y,d + 1,w + 1,ans);
            else
            {
                vis[x][y + 1] = '1';
                walk(x,y + 1,d,w + 1,ans + 1);
            }
        }
        if (d == 1)
        {
            if (x + 1 > n || s[x + 1][y] == 'x')
                walk(x,y,d + 1,w + 1,ans);
            else
            {
                vis[x + 1][y] = '1';
                walk(x + 1,y,d,w + 1,ans + 1);
            }
        }
        if (d == 2)
        {
            if (y - 1 < 1 || s[x][y - 1] == 'x')
                walk(x,y,d + 1,w + 1,ans);
            else
            {
                vis[x][y - 1] = '1';
                walk(x,y - 1,d,w + 1,ans + 1);
            }
        }
        if (d == 3)
        {
            if (x - 1 < 1 || s[x - 1][y] == 'x')
                walk(x,y,0,w + 1,ans);
            else
            {
                vis[x - 1][y] = '1';
                walk(x - 1,y,d,w + 1,ans + 1);
            }
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n,m,k,x,y,d;
        cin >>n >> m >> k >> x >> y >> d;
        memset(vis,'0',sizeof(vis));
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                cin >> s[i][j];
            }
        }
        walk(x,y,d,0,1);
    }
}
