#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,ans;
ll n,k,l[1010],a[1010][1010];
ll q,r[1010],c[1010];
void dfs(ll d,ll x,ll e,ll u)
{
	//cout<<u<<"   ";
	if(x==r[d])
	{
		for(int i=1;i<=n;i++)
		{
			if(e!=i)
			{
				for(int j=1;j<=l[i];j++)
				{
					if(a[i][j]==u)
					{
						for(int o=j+1;o<=j+k-1&&o<=l[i];o++)
						{
							if(a[i][o]==c[d])
							{
								//cout<<i<<" "<<j<<" "<<u<<"\n";
								ans=1;
								return ;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(e!=i)
			{
				for(int j=1;j<=l[i];j++)
				{
					if(a[i][j]==u)
					{
						for(int o=j+1;o<=j+k-1&&o<=l[i];o++)
						{
							dfs(d,x+1,i,a[i][o]);
						}
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
		}
		for(int i=1;i<=q;i++)
		{
			dfs(i,1,-1,1);
			cout<<ans<<"\n";
			ans=0;
		}
	}
	return 0;
}
