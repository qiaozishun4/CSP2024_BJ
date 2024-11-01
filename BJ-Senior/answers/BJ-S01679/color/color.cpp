#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N],b[N],c[5],maxn;
void dfs(int p)
{
	if(p>n)
	{
		c[0]=0,c[1]=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(c[b[i]]!=0&&a[c[b[i]]]==a[i])
			{
				ans+=a[i];
			}
			c[b[i]]=i;
		}
		maxn=max(maxn,ans);
		return;
	}
	b[p]=0;
	dfs(p+1);
	b[p]=1;
	dfs(p+1);
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		b[1]=0;
		maxn=-1;
		dfs(2);
		cout<<maxn<<endl;
	}
	return 0;
}
