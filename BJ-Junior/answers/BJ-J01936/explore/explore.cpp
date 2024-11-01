#include<bits/stdc++.h>
using namespace std;
int k,m,n,T,vx,vy,z,ans,ox,oy;
char mp[1005][1005];
void dfs(int x,int y)
{
    int nx=x,ny=y;
    if(k==0) return;
    if(z%4==0) ny++;
    if(z%4==1) nx++;
    if(z%4==2) ny--;
    if(z%4==3) nx--;
    k--;
    if(ny>m||nx>n||nx<1||ny<1||mp[nx][ny]=='x')
    {
        z++;
        dfs(x,y);
    }else
    {
        if(mp[nx][ny]=='.')
        {
            mp[nx][ny]='0';
            ans++;
        }
        dfs(nx,ny);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        cin>>vx>>vy>>z;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        dfs(vx,vy);
        cout<<ans+1<<endl;
        ans=0;
    }
    return 0;
}
