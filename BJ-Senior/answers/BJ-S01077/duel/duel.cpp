#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+7;
ll n;
ll r[N],vis[N]={},a[N];
ll ans=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(ll i=1;i<=n;i++)
	{
		a[i]=r[i];
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ll t=upper_bound(r+i+1,r+n+1,a[i])-r;
			if(t>n)
			{
				break;
			}
			if(r[t]!=-1)
			{
				vis[i]=1;
				r[t]=-1;
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
