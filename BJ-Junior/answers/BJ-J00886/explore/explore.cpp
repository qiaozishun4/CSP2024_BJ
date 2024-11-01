#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[1005][1005];
int vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","r",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,d,ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        while(k--)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x')
            {
                d+=1;
                d%=4;
            }
            else
            {
                x=nx;
                y=ny;
                if(!vis[nx][ny])
                {
                    ans++;
                }
                vis[x][y]=1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
