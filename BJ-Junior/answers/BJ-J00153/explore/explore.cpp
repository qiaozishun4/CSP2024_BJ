#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char a[N][N];
int vis[N][N];
int ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=0;
        memset(vis,0,sizeof(vis));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d,sx,sy;
        cin>>x>>y>>d;
        sx=x,sy=y;
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                cin>>a[j][p];
            }
        }
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                int x1=x,y1=y+1;
                if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x=x1,y=y1;
                    if(!vis[x][y])
                    {
                        ans++;
                        vis[x][y]=1;
                    }

                }
            }
            if(d==1)
            {
                int x1=x+1,y1=y;
                if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x=x1,y=y1;
                    if(!vis[x][y])
                    {
                        ans++;
                        vis[x][y]=1;
                    }
                }
            }
            if(d==2)
            {
                int x1=x,y1=y-1;
                if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x=x1,y=y1;
                    if(!vis[x][y])
                    {
                        ans++;
                        vis[x][y]=1;
                    }
                }
            }
            if(d==3)
            {
                int x1=x-1,y1=y;
                if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x=x1,y=y1;
                    if(!vis[x][y])
                    {
                        ans++;
                        vis[x][y]=1;
                    }
                }
            }
        }
        if(vis[sx][sy]) cout<<ans<<endl;
        else cout<<ans+1<<endl;
    }
    return 0;
}
