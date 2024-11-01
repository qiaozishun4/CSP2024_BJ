#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int minn;
void dfs(int ans,int c)
{
	if(c>n||ans>minn)
	{
		return;
	}
	if(c==n)
	{
		minn=min(minn,ans);
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(i==0&&ans==0)
		{
			continue;
		}
		dfs(ans*10+i,c+stick[i]);
	}
}
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		minn=1e9;
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<'\n';
		}
		else
		{
			dfs(0,0);
			if(minn==1e9)
			{
				cout<<"-1\n";
			}
			else
			{
				cout<<minn<<'\n';
			}
		}
	}
	return 0;
}
