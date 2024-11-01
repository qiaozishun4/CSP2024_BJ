#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll a[N],c[N];
ll n,cnt;
int main()
{
    ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            cnt++;
        c[cnt]++;
    }
    ll sum=c[1];
    for(ll i=2;i<=cnt;i++)
    {
		sum=max(0ll,sum-c[i]);
		sum+=c[i];
	}
	cout<<sum<<endl;
    return 0;
}
