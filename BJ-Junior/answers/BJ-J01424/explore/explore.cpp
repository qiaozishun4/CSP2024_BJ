#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,xa,ya,d,cnt;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
char a[1010][1010];
bool vis[1010][1010];
bool inb(int xt,int yt){
    return xt>=1&&xt<=n&&yt>=1&&yt<=m;
}
void dfs(int x,int y){
    vis[x][y]=1;
    if(cnt==k) return;
    int tx=x+dx[d],ty=y+dy[d];
    if(inb(tx,ty)&&a[tx][ty]=='.'){
        cnt++;
        dfs(tx,ty);
    }
    else{
        d=(d+1)%4;
        cnt++;
        dfs(x,y);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cnt=0;
        int ans=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>xa>>ya>>d;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j) 
                cin>>a[i][j];
        dfs(xa,ya);
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(vis[i][j]) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}