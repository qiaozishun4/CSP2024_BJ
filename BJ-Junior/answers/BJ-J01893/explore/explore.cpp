#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,nx,ny,ans;
char ma[1001][1001];
bool vis[1001][1001];
int main ()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while (t--)
    {
        memset(vis,false,sizeof(vis));
        ans=0;
        cin >> n >> m >> k >> x >> y >> d;
        vis[x][y]=true;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin >> ma[i][j];
            }
        }
        for (int i=1;i<=k;i++)
        {
            if (!d)
            {
                nx=x;
                ny=y+1;
            }
            else if (d==1)
            {
                nx=x+1;
                ny=y;
            }
            else if (d==2)
            {
                nx=x;
                ny=y-1;
            }
            else
            {
                nx=x-1;
                ny=y;
            }
            if (nx<1||nx>n||ny<1||ny>m)
            {
                d=(d+1)%4;
            }
            else if (ma[nx][ny]=='x')
            {
                d=(d+1)%4;
            }
            else
            {
                vis[nx][ny]=true;
                x=nx;
                y=ny;
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (vis[i][j])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
