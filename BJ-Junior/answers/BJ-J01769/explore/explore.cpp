#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char g[1005][1005];
int vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d,ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>g[i][j];
        }
        for(int i=1;i<=k;i++){
            int xx=x+dx[d],yy=y+dy[d];
            if(g[xx][yy]=='.'&&xx<=n&&yy<=m&&xx>0&&yy>0){
                x=xx;
                y=yy;
                if(vis[xx][yy]==0){
                    ans++;
                    vis[xx][yy]=1;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

