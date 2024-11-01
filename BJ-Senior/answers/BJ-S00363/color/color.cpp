#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e3 + 10;
int n;
int dp[maxn][maxn],a[maxn],b[maxn],maxdp[maxn];
int T;
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while (T--) {
		memset(dp,0,sizeof(dp));
		memset(b,0,sizeof(b));
		memset(maxdp,0,sizeof(maxdp));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		a[0] = -1;
		for (int i = 2; i <= n; i++) {
			b[i] = b[i - 1];
			if (a[i] == a[i - 1]) {
				b[i] += a[i];
				
			}
		}
		dp[1][0] = 0;
		for (int i = 2; i <= n; i++) {
			dp[i][0] = b[i];
			maxdp[i] = dp[i][0];
			for (int j = 1; j < i; j++) {
				dp[i][j] = maxdp[j] + b[i] - b[j + 1];
				maxdp[i] = max(maxdp[i],dp[i][j] + (a[i + 1] == a[j]) * a[j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans,dp[n][i]);
		}
		cout << ans << endl;
	}
	return 0;
}
