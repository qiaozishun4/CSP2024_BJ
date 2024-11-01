#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,m,k,a[N][N],x,y,d,vis[N][N],ans,nx,ny;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void moni(){
    nx=x+dx[d];
    ny=y+dy[d];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==0){
        vis[nx][ny]=1;
        x=nx;
        y=ny;
    }else{
        d=(d+1)%4;
    }
    return;
}
void solve(){
    ans=0;
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    vis[x][y]=1;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='x'){
                a[i][j+1]=1;
            }
        }
    }
    for(int i=1;i<=k;i++){
        moni();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]==1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return;
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}