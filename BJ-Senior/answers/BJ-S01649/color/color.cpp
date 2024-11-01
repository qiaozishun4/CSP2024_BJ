#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[100005],maxn,b[100005],c[100005],sum;
void dfs(int now)
{
	if(now>n)
	{
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>=1;j--)
			{
				if(b[i]==b[j])
				{
					if(a[i]==a[j]) c[i]=a[i];
					break;
				}
			}
		sum=0;
		for(int i=1;i<=n;i++) sum+=c[i];
		maxn=max(maxn,sum);
		return;
	}
	b[now]=1;
	dfs(now+1);
	b[now]=2;
	dfs(now+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=20)
		{
			maxn=0;
			dfs(1);
			printf("%lld\n",maxn);
		}
		else printf("0\n");
	}
	return 0;
}

