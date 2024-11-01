#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
ll t,n,k,q,l[1003],a[1003][1003],r,c;
bool dfs(ll x,ll lst,ll lstno)
{
//	cout<<x<<" "<<lst<<" "<<lstno<<"\n";
	if (x==r+1)return lst==c;
	bool ok=0;
	for (ll i=1;i<=n;i++)
	{
		if (i==lstno)continue;
		for (ll j=1;j<=l[i];j++)
		{
			if (a[i][j]==lst)
			{
				for (ll kk=j+1;kk<=j+k-1;kk++)
				{
					ok|=dfs(x+1,a[i][kk],i);
					if (ok==1)return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	faster;
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n>>k>>q;
		for (ll i=1;i<=n;i++)
		{
			cin>>l[i];
			for (ll j=1;j<=l[i];j++)
			{
				cin>>a[i][j];
			}
		}
		while (q--)
		{
			cin>>r>>c;
			cout<<dfs(1,1,0)<<endl;
		}
	}
	return 0;
}


