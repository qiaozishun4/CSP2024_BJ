#include <bits/stdc++.h>
using namespace std;
bool b[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void clr(){
    for(int i = 1;i<=1000;i++)
    {
        for(int j = 1;j<=1000;j++)
        {
            b[i][j]=vis[i][j]=0;
        }
    }
    return;
}
void solve(){
    int ans=0;
    int n,m,k;cin>>n>>m>>k;
    int x,y,d;cin>>x>>y>>d;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            char ch;cin>>ch;
            if(ch=='.')b[i][j]=0;
            else b[i][j]=1;
        }
    }vis[x][y]=1;
    ans=1;
    for(int i=1;i<=k;i++){
        int nx,ny;
        nx=x+dx[d];
        ny=y+dy[d];
        if(nx<=n&&nx>=1&&ny<=m&&ny>=1&&b[nx][ny]==0)
        {
            if(vis[nx][ny]==0)ans++;
            vis[nx][ny]=1;
            x=nx;
            y=ny;
        }
        else{
            d++;
            d%=4;
        }
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        clr();
        solve();
    }
    return 0;
}
