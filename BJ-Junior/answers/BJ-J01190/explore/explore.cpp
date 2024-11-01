#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];bool vis[1005][1005];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }vis[x][y]=true;
        while(k--){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx&&ny&&nx<=n&&ny<=m&&a[nx][ny]!='x'){
                x=nx,y=ny;
                vis[nx][ny]=true;
            }else{
                d++;
                d&=3;
            }
        }int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)ans+=vis[i][j];
        }cout<<ans<<'\n';
        if(T)memset(vis,0,sizeof(vis));
    }
    return 0;
}
