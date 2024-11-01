#include <bits/stdc++.h>
using namespace std;
int n;
int rp[200005];
int a[200005];
int c[200005];
int ans;
void toad()
{
	int last0=-1;
	int last1=-1;
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
		for(int j=i-1;j>=1;j--)
		{
			if(rp[i]==rp[j])
			{
				if(a[i]==a[j])
				{
					c[i]=a[i];
				}
				break;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		// cout<<rp[i]<<" ";
		sum+=c[i];
	}
	// cout<<endl;
	ans=max(ans,sum);
}
void dfs(int x)
{
	if(x==n+1)
	{
		toad();
		return;
	}
	rp[x]=0;
	dfs(x+1);
	rp[x]=1;
	dfs(x+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=26)
		{	
			ans=0;
			dfs(1);
		}
		else
		{
			int c1=0;
			for(int i=1;i<=n;i++)
			{
				rp[i]=-1;
			}
			for(int i=1;i<=n;i++)
			{
				if(rp[i]!=-1)
				{
					continue;
				}
				rp[i]=c1;
				for(int j=i;j<=n;j++)
				{
					if(rp[i]==rp[j])
					{
						rp[j]=c1;
					}
				}
				c1=(c1+1)%2;

			}
			toad();
		}
		cout<<ans<<endl;
	}
	return 0;
}