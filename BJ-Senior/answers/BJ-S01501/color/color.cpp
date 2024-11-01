#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[3157][3157][2];
int a[200010];
signed main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + (a[i] == a[i + 1] ? a[i] : 0));
				dp[i + 1][i][1] = max(dp[i + 1][i][1], dp[i][j][0] + (a[j] == a[i + 1] ? a[j] : 0));
				dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1] + (a[i] == a[i + 1] ? a[i] : 0));
				dp[i + 1][i][0] = max(dp[i + 1][i][0], dp[i][j][1] + (a[j] == a[i + 1] ? a[j] : 0));
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
		}
		cout << ans << endl;
	}
	return 0;
}