#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,fx,fy,fd;
char a[1005][1005];
bool vis[1005][1005];

int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};

void dfs(int x,int y,int d,int k){
    if(k == 0) return ;
    int nx = x+dx[d],ny = y+dy[d],nd = (d+1)%4;
    if(a[nx][ny] != 'x' && nx>=1 && nx<=n && ny>=1 && ny<=m){
        vis[nx][ny] = true;
        dfs(nx,ny,d,k-1);
    }
    else{
        dfs(x,y,nd,k-1);
    }
}
void putans(){
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(vis[i][j]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}


int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>fx>>fy>>fd;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j] = false;
            }
        }
        vis[fx][fy] = true;
        dfs(fx,fy,fd,k);
        putans();
    }
    return 0;
}
