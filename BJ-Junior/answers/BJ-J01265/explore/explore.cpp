#include <bits/stdc++.h>
using namespace std;
int t,ans,k;
char mp[1010][1010];
bool vis[1010][1010];
void dfs(int x,int y,int d){
    int nx,ny;
    if(k==0)return;
    if(d==0){
        nx=x,ny=y+1;
    }else if(d==1){
        nx=x+1,ny=y;
    }else if(d==2){
        nx=x,ny=y-1;
    }else {
        nx=x-1,ny=y;
    }
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
        if(!vis[nx][ny])ans++;
        vis[nx][ny]=1;
        k-=1;
        dfs(nx,ny,d);
    }else {
        k-=1;
        dfs(x,y,(d+1)%4);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int in=1;in<=t;in++){
        int n,m,sx,sy,sd;
        cin>>n>>m>>k>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        ans=1;
        vis[sx][sy]=1;
        dfs(sx,sy,sd);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}