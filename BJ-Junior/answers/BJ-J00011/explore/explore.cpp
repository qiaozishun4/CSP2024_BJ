#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,k,d,ans;
char g[1005][1005];
bool vis[1005][1005];
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
void dfs(int x,int y,int d,int k){
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    for(int i=1;i<=k;i++){
        int x1=x,y1=y;
        x1+=dx[d],y1+=dy[d];
        if(g[x1][y1]=='x'||x1>n||x1<1||y1>m||y1<1) d=(d+1)%4;
        else x=x1,y=y1,vis[x1][y1]=1;
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        dfs(x,y,d,k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
