#include<bits/stdc++.h>
using namespace std;
int _,n,a[200010],p[200010],mx=-1;
void dfs(int dep)
{
	if (dep==n+1)
	{
		int id0=-1,id1=-1,sm=0;
		for (int i=1;i<=n;i++)
		{
			if (!p[i])
			{
				if (id0==-1)
				{
					id0=i;
					continue;
				}
				if (a[id0]==a[i]) sm+=a[i];
				else sm+=0;
				id0=i;
			}
			else
			{
				if (id1==-1)
				{
					id1=i;
					continue;
				}
				if (a[id1]==a[i]) sm+=a[i];
				else sm+=0;
				id1=i;
			}
		}
		mx=max(mx,sm);
		return ;
	}
	p[dep]=0;
	dfs(dep+1);
	p[dep]=-1;
	p[dep]=1;
	dfs(dep+1);
	p[dep]=-1;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while (_--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) p[i]=-1;
		mx=-1;
		dfs(1);
		cout<<mx<<'\n';
	}
	return 0;
}
