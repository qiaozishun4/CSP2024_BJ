#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll MAXN=1e6+5;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n;
    cin>>n;
    vector<ll>fight(n);
    vector<ll>jishu(MAXN);
    vector<ll>change;
    ll sum=0;
    for(ll i=0;i<n;++i) {
        cin>>fight[i];
        if(jishu[fight[i]]==0){
            ++sum;
            change.push_back(fight[i]);
        }
        ++jishu[fight[i]];
    }
    sort(change.begin(),change.end());
    for(ll i=1;i<sum;++i){
        jishu[change[i-1]]=max(0ll,jishu[change[i-1]]-jishu[change[i]]);
        jishu[change[i]]+=jishu[change[i-1]];
        jishu[change[i-1]]=0;
    }
    cout<<jishu[change[sum-1]]<<endl;
    return 0;
}
