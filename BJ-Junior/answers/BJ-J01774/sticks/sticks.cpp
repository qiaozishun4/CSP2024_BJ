#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,n,tmp[]={6,2,5,5,4,5,6,3,7,6};
int mn=2000000000000000000;
void dfs(int cnt,int x,bool fg)
{
	if (cnt>n) return ;
	if (cnt==n)
	{
		mn=min(mn,x);
		return ;
	}
	if (!fg)
	{
		x*=10LL;
		dfs(cnt+tmp[0],x,false);
		x/=10LL;
	}
	for (int i=1;i<=9;i++)
	{
		x=x*10LL+i;
		dfs(cnt+tmp[i],x,false);
		x-=i;
		x/=10LL;
	}
}
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while (_--)
	{
		cin>>n;
		if (n>=100&&n%7==0)
		{
			for (int i=1;i<=n/7;i++) cout<<'8';
			cout<<'\n';
			continue;
		}
		mn=2000000000000000000;
		dfs(0,0,true);
		if (mn==2000000000000000000)
		{
			cout<<"-1\n";
			continue;
		}
		cout<<mn<<'\n';
	}
	return 0;
}
