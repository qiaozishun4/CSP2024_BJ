#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int M=1e6+5;

int a[N];
long long sum[N], dp[N], val[M];

inline int read()
{
	int ans=0, w=1;
	char c=getchar();
	while(c<'0' || c>'9')
		c=getchar();

	while('0'<=c && c<='9')
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans*w;
}

void work()
{
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[0]=0, a[n+1]=0;

	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1])
			sum[i]=a[i];
		else
			sum[i]=0;

	for(int i=1;i<=n;i++)
		sum[i] += sum[i-1];

	for(int i=0;i<=n;i++)
		dp[i]=0;

	dp[0]=0;
	memset(val,0xcf,sizeof(val));
	long long Max=0xcfcfcfcfcfcfcfcf;
	for(int i=0;i<n;i++)
	{
		Max=max(Max,dp[i]-sum[i+1]);
		val[a[i]]=max(val[a[i]],dp[i]-sum[i+1]+a[i]);
		dp[i+1]=max(dp[i+1],Max+sum[i+1]);
		dp[i+1]=max(dp[i+1],val[a[i+2]]+sum[i+1]);
	}
	printf("%lld\n",dp[n]);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=read();
	while(T--)
		work();
	return 0;
}