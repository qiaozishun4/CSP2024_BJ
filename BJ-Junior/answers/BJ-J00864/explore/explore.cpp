#include<bits/stdc++.h>
using namespace std;
char s[1505][1505];
int vis[1505][1505];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t = 0;
    cin>>t;
    while(t--)
    {
        int n = 0,m = 0,k = 0,x = 0,y = 0,d = 0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                vis[i][j] = 0;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin>>s[i][j];
            }
        }
        vis[x][y] = 1;
        for(int i = 1;i <= k;i++)
        {
            int nx = 0,ny = 0;
            if(d == 0)
            {
                nx = x;
                ny = y + 1;
            }
            else if(d == 1)
            {
                nx = x + 1;
                ny = y;
            }
            else if(d == 2)
            {
                nx = x;
                ny = y - 1;
            }
            else
            {
                nx = x - 1;
                ny = y;
            }
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && s[nx][ny] == '.')
            {
                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                ans += vis[i][j];
            }
        }
        cout<<ans<<"\n";
    }
}
