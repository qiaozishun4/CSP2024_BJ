#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+7;
ll T,n;
ll a[N];
ll ans=0;
ll lowbit(ll x)
{
	return x&-x;
}
void dfs(ll k,ll state)
{
	if(k>n)
	{
		ll sum=0;
		for(ll i=2;i<=n;i++)
		{
			ll t=(state>>(i-1))&1;
			if(t==0)
			{
				ll x=(~(state))&((1<<(i-1))-1);
				if(x>0)
				{
					ll p=log2(x)+1;
					if(a[p]==a[i])
					{
						sum+=a[i];
					}
				}
			}
			if(t==1)
			{
				ll x=((state-(1<<(i-1)))&((1<<i)-1));
				if(x>0)
				{
					ll p=log2(x)+1;
					if(a[p]==a[i])
					{
						sum+=a[i];
					}
				}
			}
		}
		ans=max(ans,sum);
		return;
	}
	dfs(k+1,state);
	dfs(k+1,state|(1<<(k-1)));
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
