#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[200005], rb[200005];
int dp[2005][2005];
int ans;
int main(){
	freopen("color.in", "r", stdin); freopen("color.out", "w", stdout);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(n <= 20){
		for(int i = 0; i <= (1 << n) - 1; i++){
			int j = i, k = 0;
			while(j){
				rb[++k] = j & 1;
				j >>= 1;
			}
			int cnt = 0;
			for(int i = 2; i <= n; i++)
				for(int j = i - 1; j > 0; j--){
					if(rb[i] == rb[j]){
						if(a[i] == a[j]) cnt += a[i];
						break;
					}
				}
			ans = max(ans, cnt);
		}
		cout << ans << endl; continue;}
		
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 0;
		for(int i = 2; i <= n; i++){
			for(int j = 0; j < i; j++){
				if(i != j + 1) dp[i][j] = (a[i] == a[i - 1]) * a[i] + dp[i - 1][j];
				else{
					int mx = 0;
					for(int k = 0; k < i; k++)
						dp[i][j] = max(dp[i][j], (a[i] == a[k]) * a[i] + dp[i - 1][k]);
				}
				//cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		int mx = 0;
		for(int i = 1; i <= n; i++) mx = max(mx, dp[n][i]);
		cout << mx << endl;
	}
	return 0;
}