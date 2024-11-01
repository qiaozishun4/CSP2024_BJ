#include<bits/stdc++.h>
using namespace std;
const long long dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
long long t,n,m,k,x,y,d;
bool vis[1005][1005];
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        long long ans=1;
        while(k--){
            long long nx=x+dx[d],ny=y+dy[d];
            if(nx<1||ny<1||nx>n||ny>m||a[nx][ny]=='x')d=(d+1)%4;
            else x=nx,y=ny;
            if(!vis[x][y])vis[x][y]=1,ans++;
        }
        cout<<ans<<"\n";
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
