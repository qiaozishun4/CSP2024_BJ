#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i++)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
ll dx[10]={0,1,0,-1};
ll dy[10]={1,0,-1,0};
bool vis[1005][1005][5];
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        ll n,m,k;
        cin>>n>>m>>k;
        ll x,y,d;
        cin>>x>>y>>d;
        rep(i,1,n){
            rep(j,1,m){
                cin>>a[i][j];
            }
        }
        rep(i,0,k){
            if(!vis[x][y][d]){
                vis[x][y][d]=1;
                ll nx=x+dx[d],ny=y+dy[d];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='x'){
                    x=nx,y=ny;
                    continue;
                }
                d=(d+1)%4;
            }
        }
        ll ans=0;
        rep(i,1,n){
            rep(j,1,m){
                bool flg=0;
                rep(k,0,3){
                    flg|=vis[i][j][k];
                }
                ans+=flg;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
