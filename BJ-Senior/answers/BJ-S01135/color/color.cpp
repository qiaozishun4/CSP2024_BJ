#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n;
int a[N];
bool flag[N];
int ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{	
			for(int j=i-1;j>=1;j--)
			{
				if(flag[j]==flag[i])
				{
					if(a[j]==a[i])
					{
						sum+=a[i];
					}
					break;
				}
			}
		}
		ans=max(ans,sum);
		return ;
	}
	flag[x]=1;
	dfs(x+1);
	flag[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=-1e9;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}