#include <bits/stdc++.h>
using namespace std;
int vis[1005][1005];
char mp[1005][1005];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,d,ans=1;cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>mp[i][j];
        vis[x][y]=1;
        while(k--){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]!='x'){
                x=nx,y=ny;
                if(!vis[x][y]) ans++,vis[x][y]=1;
            }else d=(d+1)%4;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//CSP rp++;
