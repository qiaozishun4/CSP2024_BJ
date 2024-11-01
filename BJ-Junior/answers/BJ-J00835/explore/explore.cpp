#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll db=0;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
struct node{
    ll x,y,d;
};
void bfs(ll x0,ll y0,ll d0,ll n,ll m,ll k,vector<vector<ll>>&v,vector<vector<char>>&a){
    queue<node>q;
    q.push({x0,y0,d0});
    v[x0][y0]++;
    while(k>0){
        ll x=q.front().x,y=q.front().y,d=q.front().d;q.pop();
        if(db&2)printf(":x=%lld:y=%lld:d=%lld:k=%lld:a=%c\n",x,y,d,k,a[x][y]);
        ll xx=x+dx[d],yy=y+dy[d],nd=d;
        if(xx>m||xx<1||yy>n||yy<1){nd=(d+1)%4;xx=x;yy=y;}
        else if(a[xx][yy]=='x'){nd=(d+1)%4;xx=x;yy=y;}
        k--;
        v[xx][yy]++;
        q.push({xx,yy,nd});
    }
}
void solve(ll n,ll m,ll k,ll x0,ll y0,ll d0,vector<vector<char>>&a){
    vector<vector<ll>>v(m+1,vector<ll>(n+1));
    bfs(y0,x0,d0,n,m,k,v,a);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++)if(v[j][i])ans++;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        ll x0,y0,d0;cin>>x0>>y0>>d0;
        vector<vector<char>>a(m+1,vector<char>(n+1));
        for(ll y=1;y<=n;y++){
            for(ll x=1;x<=m;x++)cin>>a[x][y];
        }
        solve(n,m,k,x0,y0,d0,a);
    }

    return 0;
}
