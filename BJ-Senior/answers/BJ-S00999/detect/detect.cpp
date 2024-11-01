#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n,m,l,v;
vector<ll> op;
struct car{
    ll d,v,a,cap=0;
    car(){}
    car(ll d,ll v,ll a):
        d(d),v(v),a(a)
    {}
}a[100005];
ll ca[100005];
ll rush=0;
ll ans=0x3f3f3f3f3f3f3f3fLL;// lose
vector<ll> e[100005];
void dfs(ll now){
    if(now==m+1){
        bitset<100005> vis;
        ll cnt=0;
        for(auto i:op)
            for(auto j:e[i])
                if(!vis[j]){
                    cnt++;
                    vis[j]=1;
                }
        if(cnt==rush)
            ans=min(ans,(ll)op.size());
        return;
    }
    op.push_back(now);
    dfs(now+1);
    op.pop_back();
    dfs(now+1);
    return;
}
void solve1(){
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++){
            if(ca[j]<a[i].d)
                continue;
            long double sp=sqrt(a[i].v*a[i].v+2*a[i].a*(ca[j]-a[i].d));
            // cout<<i<<" "<<j<<" "<<sp<<"\n";
            if(sp>v){
                
                e[j].push_back(i);
                if(a[i].cap==0){
                    // cout<<1<<"\n";
                    rush++;
                }
                a[i].cap=1;
            }
        }
    dfs(1);
    cout<<rush<<" "<<m-ans<<'\n';
}
bool check(ll now,ll x){
    if(ca[now]<a[x].d)
        return 0;
    long double sp=sqrt(a[x].v*a[x].v+2*a[x].a*(ca[now]-a[x].d));
    if(sp>v)
        return 1;
    return 0;
}
void solve2(){
    ll maxp=-1;
    for(ll i=1;i<=n;i++){
        ll l=1,r=m;
        bool fl=0;
        while(l<r){
            cout<<l<<" "<<r<<'\n';
            ll mid=l+(r-l)>>1;
            if(check(mid,i)){
                l=mid;
                fl=1;
            }
            else 
                r=mid-1;
        }
        if(fl)
            rush++;
        maxp=max(l,maxp);
    }
    cout<<rush<<" "<<(maxp!=-1?1:0)<<'\n';
    return;
}
void solve3(){
    for(ll i=1;i<=n;i++){
        if(check(m,i))
            rush++;
    }
    cout<<rush<<" "<<(rush==0?m:m-1)<<'\n';
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        ans=0x3f3f3f3f3f3f3f3fLL;
        rush=0;
        op.clear();
        cin>>n>>m>>l>>v;
        for(ll i=1;i<=m;i++)
            e[i].clear();
        for(ll i=1;i<=n;i++){
            ll q,w,e;
            cin>>q>>w>>e;
            a[i]=car(q,w,e);
        }
        for(ll i=1;i<=m;i++)
            cin>>ca[i];
        if(n<=20&&m<=20){
            solve1();
        }
        else
            solve3();
    }
    return 0;
}