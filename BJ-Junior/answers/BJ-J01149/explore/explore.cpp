#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,tot;
ll n,m,k,sx,sy,d;
bool vis[1050][1050];
char mp[1050][1050];
const int X[]={0,1,0,-1};
const int Y[]={1,0,-1,0};
bool inmap(ll x,ll y){
    if(x<1||x>n||y<1||y>m) return 0;
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        tot=0;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>sx>>sy>>d;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        ll x=sx,y=sy,fx=d;
        for(ll i=0;i<=k;i++){
            if(!vis[x][y]) tot++;
            vis[x][y]=1;
            ll newx=x+X[fx],newy=y+Y[fx];
            if(inmap(newx,newy)&&mp[newx][newy]=='.'){
                x=newx;
                y=newy;
            }else{
                fx=(fx+1)%4;
            }
        }
        cout<<tot<<"\n";
    }
    return 0;
}
