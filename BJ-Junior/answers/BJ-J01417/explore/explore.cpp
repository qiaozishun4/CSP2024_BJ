#include<bits/stdc++.h>
using namespace std;
const int N=1005;

int t,n,m,k,x,y,d,dir[4][2]={0,1,1,0,0,-1,-1,0};
char c;
bool vis[N][N],f[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof f);
        memset(vis,0,sizeof vis);
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.') f[i][j]=1;
            }
        vis[x][y]=1;
        while(k--)
        {
            int nx=x+dir[d][0],ny=y+dir[d][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&f[nx][ny])
                x=nx,y=ny;
            else d=(d+1)%4;
            vis[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j])
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}