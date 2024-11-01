#include <bits/stdc++.h>
using namespace std;
int t;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k,x,y,d,mp[1005][1005],vis[1005][1005],sum=1;
        string s[1005];
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            for(int j=1;j<=m;j++)
            {
                if(s[i][j-1]=='.')
                {
                    mp[i][j]=1;
                }
                else
                {
                    mp[i][j]=0;
                }
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int nx,ny;
            if(d==0)
            {
                nx=x;
                ny=y+1;
            }
            else if(d==1)
            {
                nx=x+1;
                ny=y;
            }
            else if(d==2)
            {
                nx=x;
                ny=y-1;
            }
            else
            {
                nx=x-1;
                ny=y;
            }
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]==1)
            {
                x=nx;
                y=ny;
                if(vis[x][y]==0)
                {
                    vis[x][y]=1;
                    sum++;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                vis[i][j]=0;
                mp[i][j]=0;
            }
        }
    }
    return 0;
}
