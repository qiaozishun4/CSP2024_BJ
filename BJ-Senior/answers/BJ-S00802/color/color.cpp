#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
const int N = 2007;
const int NN = 2e5 + 7;
int n;
ll a[N], ans, dp[N][N][2];
ll dp1[NN][15][2];

int main(){
	ios::sync_with_stdio(false);
	freopen("color.in", "r", stdin); freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int opA = 1;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			if(a[i] > 10) opA = 0;
		}
		if(n >= 2e4 + 7 && opA){
			memset(dp1, 128, sizeof(dp1));
			dp1[1][0][0] = dp1[1][0][1] = 0;
			for(int i = 1; i < n; ++i){
				for(int j = 0; j <= 10; ++j){
					for(int k = 0; k < 2; ++k){
						if(a[i] == a[i + 1]) dp1[i+1][j][k] = max(dp1[i+1][j][k], dp1[i][j][k] + a[i]);
						else dp1[i+1][j][k] = max(dp1[i+1][j][k], dp1[i][j][k]);
						if(a[i+1] == j) dp1[i+1][a[i]][k^1] = max(dp1[i+1][a[i]][k^1], dp1[i][j][k]+a[i+1]);
						else dp1[i+1][a[i]][k^1] = max(dp1[i+1][a[i]][k^1], dp1[i][j][k]);
					}
				}
			}
			ans = 0;
			for(int i = 0; i <= 10; ++i) for(int j = 0; j < 2; ++j) ans = max(ans, dp1[n][i][j]);
			cout << ans << endl;
			continue;
		}
		memset(dp, 128, sizeof(dp));
		dp[1][0][0] = dp[1][0][1] = 0;
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < i; ++j){
				for(int k = 0; k < 2; ++k){
					if(a[i] == a[i + 1]) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + a[i]);
					else dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
					if(a[i+1] == a[j]) dp[i+1][i][k^1] = max(dp[i+1][i][k^1], dp[i][j][k]+a[i+1]);
					else dp[i+1][i][k^1] = max(dp[i+1][i][k^1], dp[i][j][k]);
				}
			}
		}
		ans = 0;
		for(int i = 0; i < n; ++i) for(int j = 0; j < 2; ++j) ans = max(ans, dp[n][i][j]);
		cout << ans << endl;
	}
	return 0;
}