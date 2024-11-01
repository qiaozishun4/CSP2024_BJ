#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
int a[200005];
int bk[25];
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(bk[i]==bk[j])
				{
					sum+=bool(a[i]==a[j])*a[i];
					break;
				}
			}
		}
		ans=max(ans,sum);
		return;
	}
	bk[x]=0;
	dfs(x+1);
	bk[x]=1;
	dfs(x+1);
	return;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=15)
		{
			memset(bk,0,sizeof(bk));
			dfs(1);
			cout<<ans<<endl;
			continue;
		}
	}
}