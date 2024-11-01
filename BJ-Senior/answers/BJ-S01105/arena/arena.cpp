#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+10;
ll t,b[9],k,v[N];
ll n,m,a[N],c[N];
string g[N];
ll looog(ll x)
{
    ll f=0,k=0;
    while(x)
    {
        f+=x%2;
        k++;
        x/=2;
    }
    if(f>1)k++;
    return k;
}
ll solve(ll x)
{
    memset(v,0,sizeof(v));
    ll k=looog(x);
    for(ll j=1;j<=k;j++)
    {
        for(ll i=0;i<(x+1)/2;i++)
        {
            ll p=i*2;
            if(a[p]<j)
            {
                v[p]=1;
            }
            else
            {
                v[p+1]=1;
            }
        }
        x/=2;
    }
    ll ans=(1<<(k-1))*((1<<k)-1);
    for(ll i=1;i<=(1<<k);i++)
    {
        ans-=v[i]*i;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=m;i++)cin>>c[i];
    k=looog(n);
    cout<<k;
    for(ll i=1;i<=k;i++)
    {
        cin>>g[i];
    }
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<4;i++)cin>>b[i];
        for(ll i=1;i<=n;i++)a[i]=a[i]^b[i%4];
        ll ans=0;
        for(ll i=1;i<=m;i++)
        {
            ans^=(solve(c[i])*i);
        }
        cout<<ans<<"\n";
        for(ll i=1;i<=n;i++)a[i]=a[i]^b[i%4];
    }
    return 0;
}
