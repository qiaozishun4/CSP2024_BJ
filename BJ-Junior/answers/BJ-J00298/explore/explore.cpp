#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,nowd,nowx,nowy,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ans;
char g[2000][2000];
bool vis[2000][2000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        //cin>>n>>m>>k;
        scanf("%d%d%d",&nowx,&nowy,&nowd);
        //cin>>nowx>>nowy>>nowd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
                vis[i][j]=0;
            }
        }
        vis[nowx][nowy]=1;
        for(int i=1;i<=k;i++){
            int xx=nowx+dir[nowd][0];
            int yy=nowy+dir[nowd][1];
            if(xx<=n && yy<=m && xx>0 && yy>0 && g[xx][yy]=='.'){
                nowx=xx;
                nowy=yy;
                vis[xx][yy]=1;
            }else{
                nowd=(nowd+1)%4;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

