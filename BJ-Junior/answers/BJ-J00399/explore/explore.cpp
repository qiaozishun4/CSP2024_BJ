#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

char a[1010][1010];
int n,m;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[1010][1010];

int dfs(int step,int x,int y,int d,int cnt){
    if(step==0) return cnt;
    int nx=x+dx[d],ny=y+dy[d];
    if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x') d=(d+1)%4;
    else x=nx,y=ny;
    if(vis[x][y]==1){
        return dfs(step-1,x,y,d,cnt);
    }
    else{
        vis[x][y]=1;
        return dfs(step-1,x,y,d,cnt+1);
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++) for(int l=1;l<=m;l++) cin>>a[j][l];
        vis[x][y]=1;
        cout<<dfs(k,x,y,d,1)<<"\n";
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
