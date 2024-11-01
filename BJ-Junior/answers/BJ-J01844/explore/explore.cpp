#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[1005][1005];
char ditu[1005][1005];
int x,y,d;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w".stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(v,0,sizeof v);
        memset(ditu,'x',sizeof ditu);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ditu[i][j];
            }
        }
        do
        {
            v[x][y]=1;
            int nx=0,ny=0;
            if(d==0)
            {
                nx=x;
                ny=y+1;
            }
            if(d==1)
            {
                nx=x+1;
                ny=y;
            }
            if(d==2)
            {
                nx=x;
                ny=y-1;
            }
            if(d==3)
            {
                nx=x-1;
                ny=y;
            }
            if(ditu[nx][ny]=='x'||nx<1||ny<1||nx>n||ny>m)
            {
                d=(d+1)%4;
            }
            else
            {
                x=nx,y=ny;
            }
        }
        while(k--);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=m;j++)
            {
                ans+=v[i][j];
            }
        }
        cout<<ans<<'\n';
    }
}
