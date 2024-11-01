#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
char c[1005][1005];
int x,y,d,n,m,k,t;
bool chk(int xi,int yi){
    return (xi>=1&&xi<=n&&yi>=1&&yi<=m&&c[xi][yi]=='.');
}
bool vis[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>c[i][j];
        }
        memset(vis,0,sizeof vis);
        vis[x][y]=1;
        while(k--){
            int nx=x+dx[d],ny=y+dy[d];
            if(chk(nx,ny)){
                vis[nx][ny]=1;
                x=nx,y=ny;
            }
            else d=(d+1)%4;
        }
        int ans=0;;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)ans+=vis[i][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
