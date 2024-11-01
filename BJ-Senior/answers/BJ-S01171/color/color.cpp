#include <bits/stdc++.h>
using namespace std;
long long dp[2010],s1[2010],s2[2010],a[2010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
			s2[i]=s2[i-1]+(a[i-1]==a[i])*a[i];
		for(i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]+(a[i-1]==a[i])*a[i];
			s1[i]=s2[i-1];
			for(j=1;j<(i-1);j++)
			{
				dp[i]=max(dp[i],s1[j+1]+s2[i-1]-s2[j+1]+(a[j]==a[i])*a[i]);
				s1[i]=max(s1[i],s1[j+1]+s2[i-1]-s2[j+1]+(a[j]==a[i])*a[i]);
			}
		}
		cout<<dp[n]<<'\n';
	}
	return 0;
}
