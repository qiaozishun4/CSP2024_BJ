#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,r,c,t,q,l,k;
vector <ll> v[100005];
int main()
{
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(ll i=1;i<=n;i++){
            cin>>l;
            for(ll j=1;j<=l;j++){
                ll x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        while(q--){
            cin>>r>>c;
            if(r>c){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}