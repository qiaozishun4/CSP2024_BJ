#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
int sx,sy;
char mp[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int d){
    if(d<0){
        return ;
    }
    for(int i=d;i<4&&k>0;i++){
        int nx=x+dx[i],ny=y+dy[i];
        k--;
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(mp[nx][ny]=='.'){
            if(!vis[nx][ny]){
                vis[nx][ny]=1;
                ans++;
            }
            dfs(nx,ny,i);
            return ;
        }
    }
    for(int i=0;i<d&&k>0;i++){
        int nx=x+dx[i],ny=y+dy[i];
        k--;
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(mp[nx][ny]=='.'){
            if(!vis[nx][ny]){
                vis[nx][ny]=1;
                ans++;
            }
            dfs(nx,ny,i);
            return ;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int d;
        char c;
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mp[i][j]=getchar();
                //cin>>mp[i][j];
            }
            getchar();
        }
        ans=1;
        memset(vis,0,sizeof(vis));
        vis[sx][sy]=1;
        dfs(sx,sy,d);
        cout<<ans<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

