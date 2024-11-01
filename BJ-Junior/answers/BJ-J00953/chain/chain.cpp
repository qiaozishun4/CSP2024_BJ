#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n,k,q,l,r,c;
vector<ll> s[200005];

int check(ll r1,ll c1)
{
    if(r1%c1<=c1/2)return 1;
    else return 0;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(ll i=1;i<=n;i++)
        {
            cin>>l;
            for(ll j=1;j<=l;j++)
            {
                ll sj;
                cin>>sj;
                s[i].push_back(sj);
            }
        }
        for(ll i=1;i<=q;i++)
        {
            cin>>r>>c;
            cout<<check(r,c)<<"\n";
        }
    }
    return 0;
}
