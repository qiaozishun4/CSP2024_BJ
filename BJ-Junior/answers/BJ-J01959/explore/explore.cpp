#include <bits/stdc++.h>
using namespace std;
int s;
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char g[1001][1001];
int vis[1001][1001];
int xxx,yyy;
int q;
int d;
int ans=1;
void dfs(int x,int y){
    if(q==0){
        return;
    }
    int xx=x+dx[d];
    int yy=y+dy[d];
    if(xx<=n&&yy<=m&&xx>=1&&yy>=1&&g[xx][yy]!='x'){
        if(vis[xx][yy]==0){
            ans++;
            vis[xx][yy]=1;
        }
        q--;
        dfs(xx,yy);
    }else{
        q--;
        d++;
        d%=4;
        dfs(x,y);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>s;
    for(int k=1;k<=s;k++){
        cin>>n>>m>>q;
        cin>>xxx>>yyy>>d;
        ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        vis[xxx][yyy]=1;
        dfs(xxx,yyy);
        cout<<ans<<endl;
    }
    return 0;
}
