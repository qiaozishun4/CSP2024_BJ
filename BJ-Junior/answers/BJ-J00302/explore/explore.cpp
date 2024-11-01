#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,xb,yb,d,vis[1001][1001];
char g[1001][1001];
ll nd(ll x,ll d){
    if (d==1) return x+1;
    if (d==3) return x-1;
    return x;
}
ll nd2(ll y,ll d){
    if (d==0) return y+1;
    if (d==2) return y-1;
    return y;
}
int main(){
    //freopen("explore.in","r",stdin);
    //freopen("explore.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n>>m>>k;
        cin>>xb>>yb>>d;
        memset(vis,0,sizeof(vis));
        for (ll i=1;i<=n;i++) for (ll j=1;j<=m;j++) cin>>g[i][j];
        vis[xb][yb]=1;
        ll cnt=0,x=xb,y=yb;
        //cout<<x<<' '<<y<<'\n';
        while (k--){
            if (g[x][y]!='.'){
                d=(d+1)%4;
                continue;
            }
            if (nd(x,d)<1 || nd(x,d)>n || nd2(y,d)<1 || nd2(y,d)>m) d=(d+1)%4;
            else{
                x=nd(x,d);
                y=nd2(y,d);
                if (vis[x][y]==0) cnt++;
                vis[x][y]=1;
            }
            //cout<<x<<' '<<y<<'\n';
        }
        cout<<cnt+1<<'\n';
    }
    return 0;
}
