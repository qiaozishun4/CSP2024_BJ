#include<bits/stdc++.h>
using namespace std;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int t,ans;
int n,m,k;
char a[1005][1005];
bool vis[1005][1005];

void dfs(int cur,int x,int y,int dir){
    //cout<<cur<<" "<<ans<<" "<<x<<" "<<y<<" "<<a[x][y]<<endl;
    if(vis[x][y]==0) ans++;
    vis[x][y]=1;
    if(cur==k+1){
        return ;
    }
    int nx,ny;
    nx=x+dx[dir];
    ny=y+dy[dir];
    if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
        dir=(dir+1)%4;
        dfs(cur+1,x,y,dir);
    }
    else{
        dfs(cur+1,nx,ny,dir);
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        ans=0;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(1,x,y,d);
        cout<<ans<<endl;
    }
    return 0;
}
