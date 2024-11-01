#include "bits/stdc++.h"
using namespace std;
long long T, n, dp[10005], dp2[10005], last[1000005];
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		memset(last,0,sizeof(last));
		for(int i = 1;i <= n;i++)
		{
			int t;
			cin >> t;
			if(last[t] != 0)
			{
				if(dp[i - 1] < dp[last[t]] + t) dp[i] = dp[last[t]] + t,dp2[i] = max(dp[i - 1] - dp[last[t]] ,dp2[i - 1]);
				else dp2[i] = max(dp2[i - 1],dp2[last[t]] + t),dp[i] = dp[i - 1];
			}
			else dp[i] = dp[i - 1],dp2[i] = dp2[i - 1];
			last[t] = i;
		}
		cout << dp[n] + dp2[n] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
