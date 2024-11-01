#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+5;
int t,n,m,k,x,y,d,vis[N][N],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[N][N];
void solve(){
    int kx,ky;
    for(int i=1;i<=k+1;i++){
        vis[x][y]=1;
        kx=x+dx[d],ky=y+dy[d];
        if(kx>0&&kx<=n&&ky>0&&ky<=m){
            if(mp[kx][ky]=='.'){
                x=kx,y=ky;
            }else{
                d=(d+1)%4;
            }
        }else{
            d=(d+1)%4;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        solve();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
