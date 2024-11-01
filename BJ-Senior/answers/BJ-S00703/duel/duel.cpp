#include<bits/stdc++.h>
#define rd(x) scanf("%lld",&x)
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,x,ans;
map<ll,ll> mp;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    rd(n);
    while(n--){
        rd(x);
        mp[x]++;
        ans=max(ans,mp[x]);
    }
    cout<<ans;
    return 0;
}
