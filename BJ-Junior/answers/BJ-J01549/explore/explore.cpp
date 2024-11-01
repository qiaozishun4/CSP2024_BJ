#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
int n,m,k,x,y,d,t;
void go(int &x,int &y,int &d) {
    int nx=x+dx[d] ,ny=y+dy[d];
    vis[nx][ny]=true;
    if(mp[nx][ny]=='x'||nx>n||nx<1||ny>m||ny<1) {
        vis[nx][ny]=false;
        nx-=dx[d];
        ny-=dy[d];
        d=(d+1)%4;
    } x=nx ,y=ny;
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>mp[i][j];
                vis[i][j]=false;
            }
        } vis[x][y]=true;
        while(k--){
            go(x,y,d);
        } int cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(vis[i][j]==true) cnt++;
            }
        } 
        cout<<cnt<<"\n";
    }
    return 0;
}
