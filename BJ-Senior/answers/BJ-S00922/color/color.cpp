#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
ll t,n,a[100005],c[100005],ans;
void dfs(ll x)
{
	if (x==n+1)
	{
		ll sum=0;
		for (ll i=1;i<=n;i++)
		{
			ll clo=0;
			for (ll j=i-1;j>0;j--)
			{
				if (c[i]==c[j])
				{
					clo=j;
					break;
				}
			}
			if (clo==0||a[i]!=a[clo]);
			else sum+=a[i];
		}
		ans=max(ans,sum);
		return;
	}
	c[x]=0;
	dfs(x+1);
	c[x]=1;
	dfs(x+1);
}
int main()
{
	faster;
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;ans=0;
		for (ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
