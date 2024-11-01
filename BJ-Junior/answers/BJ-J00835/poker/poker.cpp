#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll n,vector<string>&a){
    ll ans=0;
    unordered_map<string,ll>m;
    for(ll i=1;i<=n;i++)m[a[i]]++;
    ans=52-m.size();
    cout<<ans;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n;cin>>n;
    vector<string>a(n+1);
    for(ll i=1;i<=n;i++)cin>>a[i];
    solve(n,a);

    return 0;
}
