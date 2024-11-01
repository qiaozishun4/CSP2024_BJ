#include <bits/stdc++.h>
using namespace std;
int r[1000005];
int vis[1000005];
int b(int left,int right,int x)
{
	int ans=-1;
	while (left<=right)
	{
		int mid=( left + right ) >> 1;
		if (r[mid]<x)
		{
			ans=mid;
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return ans;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int t=0;
	for (int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for (int i=1;i<=n;i++)
	{
		
		int e=b(1,n,r[i]);
		
		if (e==-1) continue;
		while (vis[e]&&e>=1) e--;
		if (!e) continue;
		vis[e]=1;
	}
	for (int i=1;i<=n;i++)
	{
		t+=!(vis[i]);
	}
	cout<<t;
	return 0;
}
