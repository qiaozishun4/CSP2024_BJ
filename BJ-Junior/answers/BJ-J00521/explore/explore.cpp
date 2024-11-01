#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,k;
int sx,sy,sd;
char mp[1005][1005];
bool vis[1005][1005];
int ans;
void judge(int x,int y,int d){
    for(int i=0;i<=k;i++){
        if(!vis[x][y])ans++;
        vis[x][y]=1;
        //cout<<x<<' '<<y<<' '<<d<<'\n';
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')x=nx,y=ny;
        else d=(d+1)%4;
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        memset(vis,0,sizeof vis);
        ans=0;
        judge(sx,sy,sd);
        //for(int i=1;i<=n;i++)
        //    for(int j=1;j<=m;j++)
        //        cout<<vis[i][j];
        cout<<ans<<'\n';
    }
    return 0;
}
