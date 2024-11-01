#include <bits/stdc++.h>
using namespace std;
long long T,f[200010],a[200010],n,dp[200010],ans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
		ans=0;
		scanf("%lld",&n);
		for(long long i = 1;i <= n;++i)
		{
			scanf("%lld",&a[i]);
		}
		for(long long i = n;i >= 1;--i)
		{
			f[i]=dp[i]=0;
			for(long long j = i-1;j >= 1;--j)
			{
				if(a[i]==a[j])
				{
					f[i]=j;
					ans+=a[i];
					break;
				}
			}
		}
		/*
		for(long long i = 2;i <= n;++i)
		{
			//cout<<dp[i]<<" "<<f[i]<<" "<<a[i]<<endl;//
			if(f[i]==0) dp[i]=dp[i-1];
			else dp[i]=max(dp[i-1],a[i]+dp[f[i]]+(f[i-1]==i-2?i-1:0));
		}
		printf("%lld\n",dp[n]);
		*/
		printf("%lld\n",ans);
	}
    return 0;
}
