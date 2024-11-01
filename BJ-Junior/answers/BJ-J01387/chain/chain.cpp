#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,q,l[5005][5005],book[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ll t;cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(ll i=1;i<=n;i++)
        {
            ll z;cin>>z;
            for(ll j=1;j<=z;j++)
            {
                ll x;cin>>x;
                book[x]=true;
            }
        }
        for(ll i=1;i<=q;i++)
        {
            ll x,y;cin>>x>>y;
            if(book[y]) cout<<1<<endl;
            cout<<0<<endl;
        }
    }
    return 0;
}
