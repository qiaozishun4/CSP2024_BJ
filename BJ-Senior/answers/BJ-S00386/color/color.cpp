#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
typedef long long LL;
LL n,a[N],ans;
LL dp[N][N][2];
void solve()
{
	ans = 0;
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	memset(dp,0,sizeof(dp));
	for(int i = 2;i <= n;++i)
	{
		for(int j = i-1;j >= 0;--j) dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][0]+a[i]*(a[i] == a[i-1]));
		for(int j = i-2;j >= 0;--j) dp[i][i-1][0] = max(dp[i][i-1][0],dp[i-1][j][1] + (a[i] == a[j])*a[i]);
		for(int j = i-1;j >= 0;--j) dp[i][j][1] = max(dp[i][j][1],dp[i-1][j][1]+a[i]*(a[i] == a[i-1]));
		for(int j = i-2;j >= 0;--j) dp[i][i-1][1] = max(dp[i][i-1][1],dp[i-1][j][0] + (a[i] == a[j])*a[i]);
		for(int j = i-1;j >= 0;--j) ans = max(ans,dp[i][j][0]);
		for(int j = i-1;j >= 0;--j) ans = max(ans,dp[i][j][1]);
	}
	cout << ans << '\n';
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}
