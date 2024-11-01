#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,x,y;
char a[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int k,int d){
    if(k==0) return;
    int sh=0;
    for(int i=d;sh!=4;i=(i+1)%4){
        int xx=x+dx[i],yy=y+dx[i];
        if(a[xx][yy]!='x'&&xx<=n&&xx>=1&&yy<=m&&yy>=1){
            vis[xx][yy]=1;
            dfs(xx,yy,k-1,i);
        }
        sh++;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(x,y,k,d);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1) cnt++;
                vis[i][j]=0;
            }
        }
        cout<<cnt;
    }
    return 0;
}
