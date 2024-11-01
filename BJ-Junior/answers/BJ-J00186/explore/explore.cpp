#include<bits/stdc++.h>
using namespace std;
int d,n,m,k,t,x,y;
bool b[1005][1005];
char a[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(b,false,sizeof(b));
        cin>>n>>m>>k>>x>>y>>d;
        b[x][y]=true;
        for(int i=1;i<=n;i++)
            cin>>a[i]+1;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>n || nx<1 || ny>m || ny<1 || a[nx][ny]=='x') d=(d+1)%4;
            else x=nx,y=ny;
            b[x][y]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(b[i][j]==true) ans++;
        cout<<ans<<endl;
    }
    return 0;
}