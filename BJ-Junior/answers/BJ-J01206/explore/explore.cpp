#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,k,t,sx,sy,sd;
char s[1001][1001];
bool vis[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            cin>>s[i]+1;
        }
        vis[sx][sy]=true;
        while(k--){
            int nx=sx+dx[sd],ny=sy+dy[sd];
            if(nx<1||nx>n||ny<1||ny>m){
                sd=(sd+1)%4;
                continue;
            }
            if(s[nx][ny]=='x'){
                sd=(sd+1)%4;
                continue;
            }
            sx=nx,sy=ny;
            vis[sx][sy]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=(vis[i][j]);
            }
        }
        cout<<ans<<endl;
    }
}
