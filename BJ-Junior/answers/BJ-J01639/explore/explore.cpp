#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
char a[1010][1010];
int main2()
{
    memset(vis, 0, sizeof(vis));
    int n, m, k;
    cin>>n>>m>>k;
    int x, y, d;
    cin>>x>>y>>d;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    vis[x][y]=1;
    for (int i=1;i<=k;i++)
    {
        if (d==0)
        {
            if (y<m&&a[x][y+1]=='.')
            {
                y++;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        else if (d==1)
        {
            if (x<n&&a[x+1][y]=='.')
            {
                x++;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        else if (d==2)
        {
            if (y>1&&a[x][y-1]=='.')
            {
                y--;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        else
        {
            if (x>1&&a[x-1][y]=='.')
            {
                x--;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        //cout<<x<<' '<<y<<' '<<d<<endl;
        vis[x][y]=1;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (vis[i][j]==1)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        main2();
    }
    return 0;
}
