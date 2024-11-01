#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n,m,k;
ll sx,sy,d;
ll ans=1;
char mp[1005][1005];
bool vis[1005][1005];
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
void dfs(ll x,ll y,ll d,ll stp){
    // cout<<x<<" "<<y<<" "<<d<<" "<<stp<<'\n';
    if(stp==k){
        if(!vis[x][y]){
            ans+=1;
            // cout<<"1\n";
        }
        vis[x][y]=1;
        return;
    }
    ll nx=x+dx[d],ny=y+dy[d];
    if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]!='x'){
        
        if(!vis[nx][ny]){
            ans+=1;
            // cout<<1<<'\n';
        }
        vis[nx][ny]=1;
        dfs(nx,ny,d,stp+1);
        // vis[nx][ny]=0;
    }
    else{
        dfs(x,y,(d+1)%4,stp+1);
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        memset(mp,0,sizeof mp);
        ans=1;
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                cin>>mp[i][j];
        vis[sx][sy]=1;
        dfs(sx,sy,d,0);
        cout<<ans<<'\n';
    }
    return 0;
}