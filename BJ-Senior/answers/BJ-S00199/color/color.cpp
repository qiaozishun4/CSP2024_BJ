#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2005;

int T, n;
ll val, res, ans;
ll a[MAXN];
int color[MAXN];
ll dp[MAXN];
ll sum[MAXN];

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i=1; i<=n; i++){
			scanf("%lld", &a[i]);
		}
		if (n <= 15){
			ans = 0;
			for (int i=0; i<(1<<n); i++){
				for (int j=1; j<=n; j++){
					color[j] = ((i>>(j-1))&1);	
				}
				res = 0;
				for (int j=1; j<=n; j++){
					val = 0;
					for (int k=j-1; k>=1; k--){
						if (color[j] == color[k]){
							if (a[j] == a[k]) val = a[j];
							else val = 0;
							break;	
						}
					}
					res += val;
				}
				ans = max(res, ans);
			}
			printf("%lld\n", ans);
			continue;
		}
		for (int i=2; i<=n; i++){
			if (a[i] == a[i-1]) sum[i] = sum[i-1]+a[i];
			else sum[i] = sum[i-1];
		}
		memset(dp, 0, sizeof(dp));
		for (int i=1; i<=n; i++){
			for (int j=1; j<i; j++){
				ll recent = 0;
				if (a[i] == a[j-1]) recent = a[j-1];
				dp[i] = max(dp[i], sum[i-1]-sum[j]+dp[j]+recent);
			}
		}
		ans = 0;
		for (int i=1; i<=n; i++){
			ans = max(ans, dp[i]+sum[n]-sum[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

