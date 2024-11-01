#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=1e5+15;
ll t,n,k,q,r,c,x;
bool can;
ll len[MAXN];
vector<ll> a[MAXN];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(ll i=1;i<=n;i++){
            cin>>len[i];
            for(ll j=1;j<=len[i];j++){
                cin>>x;
                a[i].push_back(x);
            }
        }
        while(q--){
            can=false;
            cin>>r>>c;
            if(r==1){
                for(ll i=1;i<=n;i++){
                    for(vector<ll>::iterator j=a[i].begin();j!=a[i].end();j++){
                        if(*j!=1||find(j,a[i].end(),c)==a[i].end()) continue;
                        if(find(j,a[i].end(),c)-j+1<=k){
                            can=true;
                            break;
                        }
                    }
                    if(can) break;
                }
            }
            if(can) cout<<"1\n";
            else cout<<"0\n";
        }
        for(ll i=1;i<=n;i++) a[i].clear();
    }
    return 0;
}
