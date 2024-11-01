#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int last[N],num[N],sum[N],dp[N],a[N];
void init(int n)
{
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)dp[i]=sum[i]=last[i]=0;
}
void run()
{
	int n;
	cin>>n;
	init(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[i]=num[a[i]];
		num[a[i]]=i;
		sum[i]=sum[i-1];
		if(a[i]==a[i-1])
		{
			sum[i]+=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(last[i])dp[i]=max(dp[i],dp[last[i]+1]+max(0ll,sum[i-1]-sum[last[i]+1])+a[i]);
		// cout<<dp[i]<<' ';
	}
	// cout<<endl;
	cout<<dp[n]<<endl;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)run();
	return 0;
}