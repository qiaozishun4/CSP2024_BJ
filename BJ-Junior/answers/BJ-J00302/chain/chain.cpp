#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,q,t,l[100001],r,c,x,tong[100001];
vector<ll>s[100001];
map<ll,ll>mp[100001];
ll anss(ll x,ll y,ll j){
    vector<ll>x1,x2;
    ll ans=1e9;
    for (ll i=0;i<s[j].size();i++) if (s[j][i]==y) x2.push_back(i);
    for (ll i=0;i<x2[x2.size()-1];i++) if (s[j][i]==x) x1.push_back(i);
    for (ll i=0;i<x1.size();i++) for (ll j=0;j<x2.size();j++) ans=min(ans,abs(x1[i]-x2[j])+1);
    return ans;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while (t--){
        memset(tong,0,sizeof(tong));
        cin>>n>>k>>q;
        for (ll i=1;i<=n;i++){
            cin>>l[i];
            for (ll j=1;j<=l[i];j++){
                cin>>x;
                s[i].push_back(x);
                tong[x]++;
                mp[i][x]++;
            }
        }
        while (q--){
            cin>>r>>c;
            if (tong[c]==0){
                cout<<"0\n";
                continue;
            }
            bool flag=0;
            for (ll i=1;i<=n;i++)
                if (mp[i][1]>0 && mp[i][c]>0 && anss(1,c,i)<=k && anss(1,c,i)>1){
                    cout<<1;
                    flag=1;
                    break;
                }
            if (flag==0) cout<<0;
            cout<<'\n';
        }
    }
    return 0;
}
