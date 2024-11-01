#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool mp[N][N],vis[N][N];int n,m,k;
bool chk(int x,int y,int d){
    int nx=x+dx[d],ny=y+dy[d];
    if(nx<1||nx>n||ny<1||ny>m) return 0;
    if(mp[nx][ny]) return 0;return 1;
}void work(int &x,int &y,int &d){
    int nx=x+dx[d],ny=y+dy[d];
    if(chk(x,y,d)) x=nx,y=ny;
    else d=(d+1)%4;
}void slv(){
    cin>>n>>m>>k;
    int x,y,d;cin>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;cin>>ch;
            if(ch=='.') mp[i][j]=0;
            else mp[i][j]=1;vis[i][j]=0;
        }
    }vis[x][y]=1;
    for(int i=1;i<=k;i++){
        work(x,y,d);
        vis[x][y]=1;
    }int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(vis[i][j]==1) ans++;
    }cout<<ans<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin>>t;while(t--) slv();
    fclose(stdin);fclose(stdout);
    return 0;
}//jp8akioi