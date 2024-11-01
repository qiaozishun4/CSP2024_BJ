#include<bits/stdc++.h>
using namespace std;
#define int long long
char puz[1111][1111];
int ans=1;
bool vis[1009][1009];
int n,m,k;
void dfs(int x,int y,int d,int dep){
    if(dep==k)return;
    int x1=x,y1=y;

  if(d==0){
            y1=y+1;
        if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&puz[x1][y1]=='.')
        {
            ans++;
            dfs(x1,y1,d,dep+1);
        }
        else dfs(x,y,(d+1)%4,dep+1);}
          if(d==1){
      x1=x+1;
        if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&puz[x1][y1]=='.')
        {
            ans++;
            dfs(x1,y1,d,dep+1);
        }
        else dfs(x,y,(d+1)%4,dep+1);}
            if(d==2){
           y1=y-1;
        if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&puz[x1][y1]=='.')
        {
            ans++;
            dfs(x1,y1,d,dep+1);
        }
        else dfs(x,y,(d+1)%4,dep+1);
            }
            if(d==3){
      x1=x-1;
        if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&puz[x1][y1]=='.')
        {
            ans++;
            dfs(x1,y1,d,dep+1);
        }
        else dfs(x,y,(d+1)%4,dep+1);
            }
}int x,y,d;
void slv(){
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    int x2=x,y2=y;
    vis[x][y]=1;
    for(int i=1;i<=k;i++){
        int x1=x2+dx[d],y1=y2+dy[d];
        if(vis[x1][y1]){x2=x1,y2=y1;continue;}
        if(!(x1>=1&&x1<=n&&y1>=1&&y1<=m&&puz[x1][y1]=='.'))d=(d+1)%4;
        else ans++,vis[x1][y1]=1,x2=x1,y2=y1;
    }
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
cin>>n>>m>>k;

ans=1;
cin>>x>>y>>d;
for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
    cin>>puz[i][j];
}
memset(vis,0,sizeof vis);
    slv();
    cout<<ans<<endl;
}}
