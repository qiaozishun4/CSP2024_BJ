#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll db=0;
void solve(ll r,ll c,ll n,ll k,ll q,vector<ll>&l,vector<vector<ll>>&a){
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=l[i];j++){
            if(a[i][j]==1||a[i][j]/10==1||a[i][j]/100==1||a[i][j]/1000==1||a[i][j]/10000==1||a[i][j]/100000==1){
                for(ll k=j;k<j+k&&k<=l[i];k++){
                    if(a[i][k]%10==c)ans=1;
                }
            }
                    if(db&2)printf(":i=%lld:j=%lld:a[i][j]=%lld:\n",i,j,a[i][j]);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ll t;cin>>t;
    while(t--){
        ll n,k,q;cin>>n>>k>>q;
        vector<ll>l(n+1);
        vector<vector<ll>>a(n+1);
        for(ll i=1;i<=n;i++){
            cin>>l[i];
            ll x;
            a[i].push_back(0);
            for(ll j=1;j<=l[i];j++)cin>>x,a[i].push_back(x);
        }
        while(q--){
            ll r,c;cin>>r>>c;
            solve(r,c,n,k,q,l,a);
        }
    }

    return 0;
}
